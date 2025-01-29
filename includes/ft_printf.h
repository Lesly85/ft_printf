/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <lesescob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:27:09 by codespace         #+#    #+#             */
/*   Updated: 2025/01/29 17:49:21 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_putchar(char c);
size_t	ft_putstr(char *str);
int		ft_printf(const char *operator, ...);

#endif
