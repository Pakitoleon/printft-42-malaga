/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: @fgonzal2 <fgonzal2@studen.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:28:03 by @fgonzal2         #+#    #+#             */
/*   Updated: 2024/02/05 15:05:19 by @fgonzal2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *a)
{
	size_t	i;

	i = 0;
	if (!a)
	{
		if (write (1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (a[i])
	{
		if (write(1, &a[i], 1) != 1)
			return (-1);
		i++;
	}
	return (i);
}
