/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <lesescob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:34:49 by codespace         #+#    #+#             */
/*   Updated: 2025/01/22 18:03:04 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *operator, ...)
{
	va_list args;
	int	i;
	int	count;

	i = 0;
	count = 0;
	va_start(args, operator);
	if (operator == NULL)
		return (-1);

	while (operator[i])
	{
		if (operator[i] == '%')
		{
			count += ft_change(args, operator[i + 1]);
			i++;
		}
		else
		{
			write(1, &operator[i], 1);
			count;
		}
		i++;
	}

	va_end(args);
	return (count);
}

//va_list: lista de argumentos
// i: indice para recorer la cadena
//count: contador total de caracteres impresos

//va_start: inicializar la lista de argumentos
//el ciclo: recorre la cadena caracter por caracter
//if/si encuentra % llamamos la funcion
