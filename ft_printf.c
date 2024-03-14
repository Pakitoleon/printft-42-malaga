/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: @fgonzal2 <fgonzal2@studen.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:49:41 by @fgonzal2         #+#    #+#             */
/*   Updated: 2024/02/08 17:49:09 by @fgonzal2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type_var(char c, va_list element);

static int	ft_porcent(char c, va_list element)
{
	int	let;

	let = 0;
	if (c != '%')
	{
		let = type_var(c, element);
		if (let == -1)
			return (-1);
		return (let);
	}
	else
	{
		if (write (1, &c, 1) == -1)
			return (-1);
		return (1);
	}
}

static int	carac_str(const char *str, va_list element, int let)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			let = let + ft_porcent(str[i + 1], element);
			if (let == -1)
				return (-1);
			i++;
		}
		else
		{
			if (write (1, &str[i], 1) == -1)
				return (-1);
			let ++;
		}
		i++;
	}
	return (let);
}

int	ft_printf(const char *str, ...)
{
	va_list		element;
	int			let;

	let = 0;
	va_start(element, str);
	let = carac_str(str, element, let);
	va_end(element);
	return (let);
}

static int	type_var(char c, va_list element)
{
	if (c == 'c')
		return (ft_putchar(va_arg(element, int)));
	if (c == 's')
		return (ft_putstr(va_arg(element, char *)));
	if (c == 'p')
		return (ft_punt_hexa(va_arg(element, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(element, int)));
	if (c == 'u')
		return (ft_num_entero(va_arg(element, unsigned int)));
	if (c == 'x')
		return (ft_minus(va_arg(element, int)));
	if (c == 'X')
		return (ft_mayus(va_arg(element, int)));
	return (0);
}

/*int main()
{
	//prueba
	ft_printf("prueba de ft_print:\n");
	ft_printf("numero entero: %d\n", 42);
	ft_printf("cadena de caracteres: %s\n", "hola mundillo!");
	ft_printf("puntero: %p\n", (void *) 0x12345678);
	ft_printf("numero hexadecimal: %x\n", 255);
	ft_printf("numero en formato decimal: %i\n", 123);
	//printf original
	printf("\nprueba de printf original: \n");
	printf("numero entero: %d\n", 42);
	printf("cadena de caracteres: %s\n", "hola mundillo!");
	printf("puntero: %p\n", (void *) 0x12345678);
	printf("numero hexadecimal: %x\n", 255);
	printf("numero en formato decimal: %i\n", 123);
}*/