/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <lesescob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:01:12 by lesescob          #+#    #+#             */
/*   Updated: 2025/01/30 23:27:57 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_unsigned(unsigned int numb)
{
	int counter;

	counter = 0;
	if (numb > 9)
		counter += ft_unsigned(numb / 10);
	counter += ft_putchar((numb % 10) + '0');
	return (counter);
}
