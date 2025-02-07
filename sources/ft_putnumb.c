/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <lesescob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:23:27 by lesescob          #+#    #+#             */
/*   Updated: 2025/02/04 14:49:39 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnumb(int n)
{
	long	numb;
	int		counter;

	numb = n;
	counter = 0;
	if (numb < 0)
	{
		counter += ft_putchar('-');
		numb = -numb;
	}
	if (numb > 9)
		counter += ft_putnumb(numb / 10);
	counter += ft_putchar((numb % 10) + 48);
	return (counter);
}

/*int	main(void)
{
	printf("caracteres: %d\n", ft_putnumb(0));
	printf("caracteres: %d\n", ft_putnumb(42));
	printf("caracteres: %d\n", ft_putnumb(-42));
	printf("caracteres: %d\n", ft_putnumb(INT_MIN));
	printf("caracteres: %d\n", ft_putnumb(INT_MAX));
}*/
