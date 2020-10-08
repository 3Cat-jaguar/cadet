/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:34:25 by ylee              #+#    #+#             */
/*   Updated: 2020/10/08 09:59:41 by ylee             ###   ########.fr       */
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

#endif
