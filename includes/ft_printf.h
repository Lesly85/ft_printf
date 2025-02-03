/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leslyescobar <leslyescobar@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:27:09 by codespace         #+#    #+#             */
/*   Updated: 2025/02/03 04:35:03 by leslyescoba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

int		ft_putchar(char c);
size_t	ft_putstr(char *str);
int		ft_putnumb(int n);
int		ft_unsigned(unsigned int numb);
int		ft_puthexa_x(unsigned long n);
int		ft_puthexa_XX(unsigned long n);
int		ft_putptr(void *ptr);
int		ft_change(va_list args, char formato);
int		ft_printf(const char *operator, ...);

#endif
