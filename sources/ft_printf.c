/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <lesescob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:26:30 by lesescob          #+#    #+#             */
/*   Updated: 2025/02/04 15:25:44 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_change(va_list args, char formato)
{
	int	counter;

	counter = 0;
	if (formato == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (formato == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (formato == 'd' || formato == 'i')
		counter += ft_putnumb(va_arg(args, int));
	else if (formato == 'u')
		counter += ft_unsigned(va_arg(args, unsigned int));
	else if (formato == 'p')
		counter += ft_putptr(va_arg(args, void *));
	else if (formato == 'x')
		counter += ft_puthexa_x(va_arg(args, unsigned int));
	else if (formato == 'X')
		counter += ft_puthexa_upper(va_arg(args, unsigned int));
	else if (formato == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_change(args, str[i]);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

/*#include "ft_printf.h"
#include <stdio.h> // Para comparar con printf original

int	main(void)
{
	int		num = -42;
	unsigned int unum = 4294967295;
	char	c = 'A';
	char	*str = "Hola3mundo%";
	char	*null_str = NULL;
	void	*ptr = &num;
	void	*null_ptr = NULL;
	int	count = 0;

	// Prueba con caracteres
	count = ft_printf("1. Caracter: %c\n", c);
	ft_printf("count = %d\n", count);
	count = printf("1. Caracter: %c\n", c);
	ft_printf("count = %d\n", count);


	// Prueba con strings
	ft_printf("2. String: %s\n", str);
	printf("2. String: %s\n", str);

	// Prueba con string NULL
	ft_printf("3. String NULL: %s\n", null_str);
	printf("3. String NULL: %s\n", null_str);

	// Prueba con punteros
	ft_printf("4. Puntero: %p\n", ptr);
	printf("4. Puntero: %p\n", ptr);

	// Prueba con puntero NULL
	ft_printf("5. Puntero NULL: %p\n", null_ptr);
	printf("5. Puntero NULL: %p\n", null_ptr);

	// Prueba con enteros decimales (positivos y negativos)
	ft_printf("6. Entero positivo: %d\n", 42);
	printf("6. Entero positivo: %d\n", 42);
	ft_printf("7. Entero negativo: %d\n", num);
	printf("7. Entero negativo: %d\n", num);

	// Prueba con enteros sin signo
	ft_printf("8. Entero sin signo: %u\n", unum);
	printf("8. Entero sin signo: %u\n", unum);

	// Prueba con hexadecimal en minúsculas
	ft_printf("9. Hexadecimal minúsculas: %x\n", 255);
	printf("9. Hexadecimal minúsculas: %x\n", 255);

	// Prueba con hexadecimal en mayúsculas
	ft_printf("10. Hexadecimal mayúsculas: %X\n", 255);
	printf("10. Hexadecimal mayúsculas: %X\n", 255);

	// Prueba con el carácter '%'
	ft_printf("11. Porcentaje: %%\n");
	printf("11. Porcentaje: %%\n");

	// Prueba con combinaciones
	ft_printf("12. mix: Char %c, String %s, Número %d, Hex %x, Puntero %p\n",
		c, str, num, 255, ptr);
	printf("12. mix: Char %c, String %s, Número %d, Hex %x, Puntero %p\n",
		c, str, num, 255, ptr);

	return (0);
}

//ft_printf**
//va_list*: lista de argumentos
//i: iterador
//count: contador total de caracteres impresos
//va_start*: inicializar la lista de argumentos
//el ciclo: recorre la cadena caracter por caracter

//gcc -Wall -Wextra -Werror -Iincludes libftprintf.a*/
