/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <lesescob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:34:49 by codespace         #+#    #+#             */
/*   Updated: 2025/01/29 19:12:06 by lesescob         ###   ########.fr       */
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
//if/si encuentra % y hay un caracter despues
//if: caso especial '%%' imprime uno solo, escribe '%' en el output
//else: llamamos la funcion ft_change para manejar el operador (%c, %s, %d, etc)
//else: si no es '%', simplemente imprimimos el caracter actual con write
//i++: avanza al proximo caractere de la cadena
//va_end*: cerramos la lista de argumentos variables
//return(count): devolvemos el numero totale de caracteres impresos
