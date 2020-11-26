/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:37:19 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/11 15:36:08 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

int		get_next_line(int fd, char **line);
int		ft_strchrchr(char *s, int c);
char	*ft_strcpycpy(char *dst, char *src, size_t n);
char	*ft_strndupup(char *s1);
char	*ft_strjoinjoin(char *s1, char *s2);

#endif
