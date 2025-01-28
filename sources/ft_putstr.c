/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:00:59 by lesescob          #+#    #+#             */
/*   Updated: 2025/01/28 11:45:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "(nill)", 6)
			return (6);
	}
	while (str[i] != '\0')
		i++;
	write(1, s, i);
	return (i);
}

/*int main()
{
	char str1[] = "hola";
	char *str2 = NULL;
	char str3[] = "123 uno!";

	printf(" ,lun:%zu\n", ft_putstr(str1));
	printf(" ,lun:%zu\n", ft_putstr(str2));
	printf(" ,lung:%zu\n", ft_putstr(str3));

	return (0);
}*/
