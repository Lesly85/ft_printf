/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leslyescobar <leslyescobar@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:26:30 by lesescob          #+#    #+#             */
/*   Updated: 2025/02/03 03:30:33 by leslyescoba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_change(va_list args, char formato)
{
	int	counter;

	counter = 0;
	if (formato == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (formato == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (formato == 'd' || formato == 'i')
		counter += ft_putnumb(va_arg(args, int));
	else if (formato == 'u')
		counter += ft_unsigned(va_arg(args, unsigned int));
	else if (formato == 'p')
		counter += ft_putptr(va_arg(args, void *));
	else if (formato == 'x')
		counter += ft_puthexa(va_arg(args, unsigned int));
	else if (formato == 'X')
		counter += ft_puthexa(va_arg(args, unsigned int));
	else if (formato == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *operator, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, operator);
	while (operator[i])
	{
		if (operator[i] == '%' && operator[i + 1])
		{
			i++;
			count += ft_change(args, operator[i]);
		}
		else
			count += write(1, &operator[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

//ft_printf**
//va_list*: lista de argumentos
//i: iterador
//count: contador total de caracteres impresos
//va_start*: inicializar la lista de argumentos
//el ciclo: recorre la cadena caracter por caracter y hace el control de % al final

