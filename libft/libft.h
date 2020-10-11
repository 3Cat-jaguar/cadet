/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:34:25 by ylee              #+#    #+#             */
/*   Updated: 2020/10/11 18:35:35 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_strlen(const char *s);
int		ft_strlcpy(char *dst, const char *src, int size);
int		ft_strlcat(char *dst, const char *src, int size);
int		ft_isalpha(int c);
int		ft_isdigit(int d);
int		ft_isalnum(int a);
int		ft_isascii(int c);
int		ft_isprint(int p);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
void	*ft_memset(void *ptr, int value, int num);
void	ft_bzero(void *s, int n);
void	*ft_memcpy(void *dst, const void *src, int n);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
void	*ft_memmove(void *dst, const void *src, int n);
void	*ft_memccpy(void *dst, const void *src, int c, int n);
void	*ft_memchr(const void *str, int c, int n);
int		ft_memcmp(const void *str1, const void *str2, int n);
char	*ft_strnstr(const char *s1, const char *s2, int n);

#endif
