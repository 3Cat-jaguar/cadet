/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amin <amin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:14:36 by amin              #+#    #+#             */
/*   Updated: 2020/11/25 16:27:45 by amin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(const char *dst, const char *src);
char		*ft_strdup(const char *s1);
ssize_t		ft_read(int fd, void *buff, size_t nbyte);
ssize_t		ft_write(int fd, void *buff, size_t nbyte);

#endif
