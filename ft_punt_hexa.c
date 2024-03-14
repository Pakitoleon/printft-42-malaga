/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_punt_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: @fgonzal2 <fgonzal2@studen.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:08:47 by @fgonzal2         #+#    #+#             */
/*   Updated: 2024/02/08 18:12:33 by @fgonzal2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa_pointer( char *str, unsigned long n, int c)
{
	unsigned long	b;

	b = ft_strlen(str);
	if (n >= b)
	{
		c = hexa_pointer(str, n / b, c);
		if (c == -1)
			return (-1);
		if (write (1, &str[n % b], 1) == -1)
			return (-1);
		c++;
	}
	if (n < b)
	{
		if (write(1, &str[n], 1) == -1)
			return (-1);
		c++;
	}
	return (c);
}

int	ft_punt_hexa(void *p)
{
	int					let;
	unsigned long		pointer;

	let = 0;
	pointer = (unsigned long)p;
	if (write(1, "0x", 2) != 2)
		return (-1);
	let = hexa_pointer("0123456789abcdef", pointer, let);
	if (let == -1)
		return (-1);
	let += 2;
	return (let);
}
