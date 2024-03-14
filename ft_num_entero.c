/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_entero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: @fgonzal2 <fgonzal2@studen.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:28:53 by @fgonzal2         #+#    #+#             */
/*   Updated: 2024/02/05 15:05:35 by @fgonzal2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_num_entero(unsigned int num)
{
	int	let;

	let = 0;
	if (num > 9)
	{
		let = ft_num_entero (num / 10);
		if (let == -1)
			return (-1);
		num = num % 10;
	}
	if (num <= 9)
	{
		if (ft_putchar(('0' + num)) == -1)
			return (-1);
		let++;
	}
	return (let);
}
