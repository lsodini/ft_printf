/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:46:26 by marvin            #+#    #+#             */
/*   Updated: 2024/02/02 17:46:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

int				ft_printf(const char *in, ...);
int				ft_putchar(char c);
int				ft_putnbr(long n);
int				ft_putstr(char *str);
int				ft_numhex_low(unsigned int num);
int				ft_numhex_up(unsigned int num);
int				ft_pointer_numhex(uintptr_t ptr, int w);
#endif
/*
va_list -> type for iterating arguments
va_start -> start iterating arguments with a va_list
va_arg -> Retrieve an argument
va_end -> free a va_list
va_copy -> Copy contents of one va_list to another
*/