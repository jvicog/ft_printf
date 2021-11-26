/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 11:26:51 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/11/26 15:44:57 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

static int	my_dictionary(char s, va_list args)
{
	int		cnt;

	cnt = 0;
	if (s == 's')
		cnt += ft_putstr_fd(va_arg(args, char *), 1);
	else if (s == 'c')
		cnt += ft_putchar_fd(va_arg(args, int), 1);
	else if (s == 'd' || s == 'i')
		cnt += ft_itoa(va_arg(args, int));
	else if (s == 'u')
		cnt += ft_itoa((unsigned int)va_arg(args, int));
	else if (s == '%')
		cnt = ft_putchar_fd(s, 1);
	else if (s == 'p')
	{
		write(1, "0x", 2);
		cnt += ft_tohexadecimal(va_arg(args, unsigned long long), 0) + 2;
	}
	else if (s == 'x')
		cnt += ft_tohexadecimal(va_arg(args, unsigned int), 0);
	else if (s == 'X')
		cnt += ft_tohexadecimal(va_arg(args, unsigned int), 1);
	return (cnt);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			cnt;
	va_list		args;

	i = 0;
	cnt = 0;
	va_start (args, str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			i++;
			cnt += my_dictionary(str[i], args);
		}
		else
		{
			write (1, &str[i], 1);
			cnt++;
		}
		i++;
	}
	va_end(args);
	return (cnt);
}
