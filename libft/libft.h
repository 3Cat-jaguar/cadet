/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:34:25 by ylee              #+#    #+#             */
/*   Updated: 2020/10/12 14:59:18 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

int		ft_strlen(const char *s);
int		ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strlcat(char *dst, const char *src, size_t size);
int		ft_isalpha(int c);
int		ft_isdigit(int d);
int		ft_isalnum(int a);
int		ft_isascii(int c);
int		ft_isprint(int p);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif
