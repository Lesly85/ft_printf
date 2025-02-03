/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leslyescobar <leslyescobar@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:14:32 by leslyescoba       #+#    #+#             */
/*   Updated: 2025/02/03 04:19:23 by leslyescoba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

