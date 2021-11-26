/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:51:06 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/11/26 15:30:27 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_fd(char c, int fd)
{
	void	*buffer;

	buffer = &c;
	write(fd, buffer, sizeof(char));
	return (1);
}
