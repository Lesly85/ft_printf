/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <lesescob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:34:49 by codespace         #+#    #+#             */
/*   Updated: 2025/01/29 20:04:45 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_change(va_list args, char operator)
{
	int	counter;

	counter = 0;
	if (operator == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (operator)
}

int	ft_printf(const char *operator, ...)
{
	va_list args;
	int	count;
	int	i;

	count = 0;
	i = 0;
	va_start(args, operator);
	while (operator[i])
	{
		if (operator[i] == '%' && operator[i + 1])
		{
			i++;
			count += ft_change(&args, operator[i]);
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

