/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:37:03 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/19 21:28:16 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			split_line(char **line, char **note, int n)
{
	char	*tmp;
	int		len;

	(*note)[n] = 0;
	*line = ft_strndupup(*note);
	len = ft_strlen(*note + n + 1);
	if (len == 0)
	{
		free(*note);
		*note = 0;
		return (1);
	}
	tmp = ft_strndupup(*note + n + 1);
	free(*note);
	*note = tmp;
	return (1);
}

int			return_line(char **line, char **note, int size)
{
	int	newline;

	if (size < 0)
		return (-1);
	if (*note && (newline = ft_strchrchr(*note, '\n')) >= 0)
		return (split_line(line, note, newline));
	else if (*note)
	{
		*line = *note;
		*note = 0;
		return (0);
	}
	*line = ft_strndupup("");
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*note[OPEN_MAX];
	static char buff[BUFFER_SIZE + 1];
	int			byte;
	int			line_point;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((byte = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[byte] = 0;
		note[fd] = ft_strjoinjoin(note[fd], buff);
		if ((line_point = ft_strchrchr(note[fd], '\n')) >= 0)
			return (split_line(line, &note[fd], line_point));
	}
	return (return_line(line, &note[fd], byte));
}
