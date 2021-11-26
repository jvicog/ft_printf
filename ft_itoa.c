/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:21:06 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/11/26 15:44:52 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_aux_itoa(long number, char *ptr, int count)
{
	while (number != 0)
	{
		ptr[count-- - 1] = (number % 10) + 48;
		number = number / 10;
	}
	if (count != 0)
		ptr[0] = '-';
}

size_t	ft_itoa(long long n)
{
	long		number;
	int			count;
	char		*ptr;

	number = n;
	count = 0;
	while (number != 0 && count++ != -1)
		number = number / 10;
	number = n;
	if (n <= 0 && count++ != -1)
		number = number * -1;
	ptr = (char *) malloc(sizeof(char) * (count + 1));
	if (ptr == NULL)
		return (0);
	ptr[count] = '\0';
	if (n == 0 && count-- != -1)
		ptr[0] = 48;
	ft_aux_itoa(number, ptr, count);
	count = (size_t) ft_putstr_fd(ptr, 1);
	free (ptr);
	return (count);
}
