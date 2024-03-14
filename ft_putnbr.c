/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: @fgonzal2 <fgonzal2@studen.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:10:42 by @fgonzal2         #+#    #+#             */
/*   Updated: 2024/03/02 09:45:57 by @fgonzal2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_min(int n)
{
	(void)n;
	if (write(1, "-2147483648", 11) != 11)
		return (-1);
	return (11);
}

int	ft_putnbr(int n)
{
	int	let;

	let = 0;
	if (n == -2147483648)
		return (int_min(n));
	if (n < 0 && ++let)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		n = -n;
	}
	if (n > 9) 
	{
		let += ft_putnbr(n / 10); 
		if (let == -1) 
			return (-1); 
		n = n % 10;
	}
	if (n <= 9) 
	{
		if (ft_putchar (('0' + n)) == -1) 
			return (-1); 
		let++;
	}
	return (let);
}
