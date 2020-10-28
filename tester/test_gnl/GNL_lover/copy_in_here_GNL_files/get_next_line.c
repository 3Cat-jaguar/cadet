/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:56:33 by ylee              #+#    #+#             */
/*   Updated: 2020/10/28 10:04:39 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*restline[OPEN_MAX];
	char		*buf;
	char		*tmp;
	int			idx;
	ssize_t		read_len;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	read_len = 0;
	while (read_len >= 0)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len < 0)
			return (-1);
		buf[read_len] = '\0';
		idx = 0;
		if (read_len == 0 && !restline[fd])
		{
			*line = ft_strdup("");
			return (0);
		}
		else if (read_len == 0 && restline[fd])
		{
			restline[fd] = ft_strjoin(restline[fd], buf);
			while (restline[fd][idx])
			{
				if (restline[fd][idx] == '\n')
				{
					restline[fd][idx] = '\0';
					*line = ft_strdup(restline[fd]);
					tmp = ft_strdup(&restline[fd][idx + 1]);
					free(restline[fd]);
					restline[fd] = tmp;
					return (1);
				}
				idx++;
			}
			*line = ft_strdup(restline[fd]);
			free(restline[fd]);
			return (0);
		}
		else if (read_len > 0)
		{
			restline[fd] = ft_strjoin(restline[fd], buf);
			while (restline[fd][idx])
			{
				if (restline[fd][idx] == '\n')
				{
					restline[fd][idx] = '\0';
					*line = ft_strdup(restline[fd]);
					tmp = ft_strdup(&restline[fd][idx + 1]);
					free(restline[fd]);
					restline[fd] = tmp;
					return (1);
				}
				idx++;
			}
			if (read_len < BUFFER_SIZE)
			{
				*line = ft_strdup(restline[fd]);
				free(restline[fd]);
				return (0);
			}
		}
	}
	return (0);
}
