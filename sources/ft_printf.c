/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leslyescobar <leslyescobar@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:26:30 by lesescob          #+#    #+#             */
/*   Updated: 2025/02/03 05:15:16 by leslyescoba      ###   ########.fr       */
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
		counter += ft_puthexa_XX(va_arg(args, unsigned int));
	else if (formato == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *operator, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, operator);
	while (operator[i])
	{
		if (operator[i] == '%')
		{
			i++;
			count += ft_change(args, operator[i]);
		}
		else
			count += write(1, &operator[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

#include "ft_printf.h"
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

	// Prueba con caracteres
	ft_printf("1. Caracter: %c\n", c);
	printf("1. Caracter: %c\n", c);

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
	ft_printf("12. Combinado: Char %c, String %s, Número %d, Hex %x, Puntero %p\n",
		c, str, num, 255, ptr);
	printf("12. Combinado: Char %c, String %s, Número %d, Hex %x, Puntero %p\n",
		c, str, num, 255, ptr);

	return (0);
}

//ft_printf**
//va_list*: lista de argumentos
//i: iterador
//count: contador total de caracteres impresos
//va_start*: inicializar la lista de argumentos
//el ciclo: recorre la cadena caracter por caracter y hace el control de % al final

//gcc -Wall -Wextra -Werror -Iincludes sources/ft_printf.c sources/libftprintf.a
// -o test_printf
