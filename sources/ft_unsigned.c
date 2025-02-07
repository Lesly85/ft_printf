/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <lesescob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:01:12 by lesescob          #+#    #+#             */
/*   Updated: 2025/02/06 17:43:16 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int numb)
{
	int	counter;

	counter = 0;
	if (numb > 9)
		counter += ft_unsigned(numb / 10);
	counter += ft_putchar((numb % 10) + '0');
	return (counter);
}
/*explicacion codigo:
la funcion recibe un numero sin signo
la variable sirve para contar cuanto caracteres se imprimen
if: si el numero tiene mas de una cifra
se hace la recursion con numb /10 y esto va reduciendo el numero
hasta llegar a una sola cifra.
La recursión divide el número eliminando el último dígito en cada
paso (numb / 10). Cuando regresamos de la recursión, imprimimos
el último dígito de cada llamada

*/
