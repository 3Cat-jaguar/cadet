/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:56:33 by ylee              #+#    #+#             */
/*   Updated: 2020/11/05 14:12:01 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		check_read(char **line, char *restline, char **buf, int read_len)
{
	if (read_len < 0)
	{
		free(*buf);
		*buf = NULL;
		return (-1);
	}
	else if (read_len == 0 && !restline)
	{
		*line = ft_strdup("");
		free(*buf);
		*buf = NULL;
		return (0);
	}
	return (1);
}

int		check_eol(char **line, char **restline, char **buf)
{
	int		idx;
	char	*tmp;

	idx = 0;
	while ((*restline)[idx])
	{
		if ((*restline)[idx] == '\n')
		{
			(*restline)[idx] = '\0';
			*line = ft_strdup(*restline);
			tmp = ft_strdup(&(*restline)[idx + 1]);
			free(*restline);
			*restline = NULL;
			*restline = tmp;
			free(*buf);
			*buf = NULL;
			return (1);
		}
		idx++;
	}
	return (0);
}

int		check_txt(char **line, char **restline, char **buf, int read_len)
{
	(*buf)[read_len] = '\0';
	*restline = ft_strjoin(*restline, *buf);
	if (check_eol(line, restline, buf) == 1)
		return (1);
	if (read_len < BUFFER_SIZE)
	{
		*line = ft_strdup(*restline);
		free(*restline);
		*restline = NULL;
		free(*buf);
		*buf = NULL;
		return (0);
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char	*restline[OPEN_MAX];
	char		*buf;
	ssize_t		read_len;
	int			result;

	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	read_len = read(fd, buf, BUFFER_SIZE);
	if ((result = check_read(line, restline[fd], &buf, read_len)) <= 0)
		return (result);
	while (read_len >= 0)
	{
		result = check_txt(line, &restline[fd], &buf, read_len);
		if (result >= 0)
			return (result);
		read_len = read(fd, buf, BUFFER_SIZE);
	}
	return (-1);
}
