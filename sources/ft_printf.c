/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <lesescob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:34:49 by codespace         #+#    #+#             */
/*   Updated: 2025/01/28 19:24:39 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_change()


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
		if (operator[i] == '%' && operator[i + 1])
		{
			if (operator[i + 1] == '%')
				count += write(1, "%", 1);
			else
				count += ft_change(args, operator[i + 1]);
			i++;
		}
		else
			count += write(1, &operator[i], 1);
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
//if/si encuentra % y hay un caracter despues
//if: caso especial '%%' imprime uno solo, escribe '%' en el output
//else: llamamos la funcion ft_change para manejar el operador (%c, %s, %d, etc)
//else: si no es '%', simplemente
