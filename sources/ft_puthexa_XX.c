/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_XX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leslyescobar <leslyescobar@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:20:10 by leslyescoba       #+#    #+#             */
/*   Updated: 2025/02/03 04:21:48 by leslyescoba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_XX(unsigned long n)
{
	int		counter;
	char	*base;
	char	digit;

	base = "0123456789ABCDEF";
	counter = 0;
	if (n >= 16)
		counter += ft_puthexa_XX(n / 16);
	digit = base[n % 16];
	counter += ft_putchar(digit);
	return (counter);
}
