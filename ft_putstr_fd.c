/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:27:54 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/11/12 20:05:37 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr_fd(char *s, int fd)
{
	void	*buffer;
	size_t	len;

	if (s != NULL)
	{
		buffer = s;
		write(fd, buffer, sizeof(char) * ft_strlen(s));
		len = ft_strlen(s);
		return (len);
	}
	else
	{
		write(fd, "(null)", 6);
		return (6);
	}
}
