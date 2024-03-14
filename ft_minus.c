/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: @fgonzal2 <fgonzal2@studen.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:52:01 by @fgonzal2         #+#    #+#             */
/*   Updated: 2024/02/13 10:03:23 by @fgonzal2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	puthexa_long(char *bstr, unsigned long n, int c)
{
	unsigned long	b;

	b = ft_strlen(bstr);
	if (n >= b)
	{
		c = puthexa_long(bstr, n / b, c);
		if (c == -1)
			return (-1);
		if (write(1, &bstr[n % b], 1) == -1)
			return (-1);
		c++;
	}
	else if (n < b)
	{
		if (write(1, &bstr[n], 1) == -1)
			return (-1);
		c++;
	}
	return (c);
}

static int	puthexa_uns(char *bstr, unsigned int n, int c)
{
	unsigned int	b;

	b = ft_strlen(bstr);
	if (n >= b)
	{
		c = puthexa_uns(bstr, n / b, c);
		if (c == -1)
			return (-1);
		if (write(1, &bstr[n % b], 1) == -1)
			return (-1);
		c++;
	}
	else if (n < b)
	{
		if (write(1, &bstr[n], 1) == -1)
			return (-1);
		c++;
	}
	return (c);
}

int	ft_minus(int n)
{
	int	let;

	let = 0;
	if (n >= 0)
		let = puthexa_long("0123456789abcdef", n, let);
	else if (n < 0)
		let = puthexa_uns("0123456789abcdef", n, let);
	return (let);
}
