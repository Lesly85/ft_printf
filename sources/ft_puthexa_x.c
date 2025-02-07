/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <lesescob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:14:32 by leslyescoba       #+#    #+#             */
/*   Updated: 2025/02/06 14:43:08 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_x(unsigned long n)
{
	int		counter;
	char	*base;
	char	digit;

	base = "0123456789abcdef";
	counter = 0;
	if (n >= 16)
		counter += ft_puthexa_x(n / 16);
	digit = base[n % 16];
	counter += ft_putchar(digit);
	return (counter);
}
/*explicacion codigo:
variables:
counter: cuenta quantos caracteres se imprimen
base: puntero a una cadena de los digitos hexadecimales(16)
digit: almacena cada caracter de cada digito hexa
if: si el num es >= a 16, se divide para procesarlo en partes
recursiva: se usa para imprimir los digitos
digit = base[n % 16] obtiene el caracter correspondiente al digito
		menos significativo
counter += ft_putchar(digit): imprime el digito y se suma al contador
*/
