/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leslyescobar <leslyescobar@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:22:36 by leslyescoba       #+#    #+#             */
/*   Updated: 2025/02/03 05:03:48 by leslyescoba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				count;

	if (!ptr)
		return (ft_putstr("0x0"));

	address = (unsigned long)ptr;
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthexa_x(address);
	return (count);
}

