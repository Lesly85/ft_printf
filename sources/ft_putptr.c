/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <lesescob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:22:36 by leslyescoba       #+#    #+#             */
/*   Updated: 2025/02/06 22:10:36 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	address = (unsigned long)ptr;
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthexa_x(address);
	return (count);
}
/*la funcion recibe un puntero de tipo void
variables**
address: almacena la direccion del puntero y
es de tipo unsigned long que almacena solo numeros positivos
count: almacena cantidad caracteres impresos
if: controllo si el puntero es NULL llamo la funcion ft_putstr
y imprime (nil).
casto il puntero di tipo void a tipo unsigned int, y inicializo el count
count += ft_putstr("0x"):Se imprime la cadena "0x" indica que se mostrará un
número hexadecimal y se suma su longitud a "count".
count += ft_puthexa_x(address):  Se convierte la dirección en hexadecimal e
imprime el valor, sumando la cantidad de caracteres impresos a "count"
return: valor total de caracteres imprimidos*/
