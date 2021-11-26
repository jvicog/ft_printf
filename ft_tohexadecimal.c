/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohexadecimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:12:10 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/11/26 16:27:55 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	invert_num(unsigned long long num, int mayus,
					char *invertido, size_t j);

size_t	ft_tohexadecimal(unsigned long long num, int mayus)
{
	char				*invertido;
	size_t				j;
	unsigned long long	aux_num;

	if (num == 0)
		return (ft_putchar_fd('0', 1));
	aux_num = num;
	j = 0;
	while (num != 0)
	{
		num /= 16;
		j++;
	}
	invertido = malloc(sizeof(char) * j + 1);
	if (invertido == NULL)
		return (0);
	invertido[j] = 0;
	invert_num(aux_num, mayus, invertido, j);
	j = ft_putstr_fd(invertido, 1);
	free (invertido);
	return (j);
}

static	void	invert_num(unsigned long long num, int mayus,
						char *invertido, size_t j)
{
	long unsigned		conversor;
	char				aux;
	int					isMayus;

	if (mayus == 0)
		isMayus = 87;
	else
		isMayus = 55;
	while (num != 0)
	{
		conversor = num % 16;
		if (conversor < 10)
			aux = 48 + conversor;
		else
			aux = isMayus + conversor;
		invertido[--j] = aux;
		num /= 16;
	}
}
