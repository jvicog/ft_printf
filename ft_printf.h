/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:26:25 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/11/26 15:44:55 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_printf(const char *str, ...);
size_t				ft_strlen(const char *cadena);
size_t				ft_itoa(long long n);
size_t				ft_putchar_fd(char c, int fd);
size_t				ft_putstr_fd(char *s, int fd);
size_t				ft_tohexadecimal(unsigned long long num, int mayus);
unsigned long long	to_positive(int i);
#endif
