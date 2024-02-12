/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsodini <lsodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:51:49 by lsodini           #+#    #+#             */
/*   Updated: 2024/02/12 15:51:49 by lsodini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print(va_list arg, const char wit)
{
	int	tipo;

	tipo = 0;
	if (wit == 'c')
		tipo = ft_putchar(va_arg(arg, int));
	if (wit == 's')
		tipo = ft_putstr(va_arg(arg, char*));
	if (wit == 'p')
		tipo = ft_pointer_numhex(va_arg(arg, uintptr_t), 0);
	if (wit == 'd' || wit == 'i')
		tipo = ft_putnbr(va_arg(arg, int));
	if (wit == 'u')
		tipo = ft_putnbr(va_arg(arg, unsigned int));
	if (wit == 'x')
		tipo = ft_numhex_low(va_arg(arg, unsigned int));
	if (wit == 'X')
		tipo = ft_numhex_up(va_arg(arg, unsigned int));
	if (wit == '%')
		tipo = ft_putchar('%');
	return (tipo);
}

int	ft_printf(const char *i, ...)
{
	int	j;
	int	tipo;
	va_list arg;

	if (!i)
		return (0);
	j = 0;
	tipo = 0;
	va_start(arg, i);
	while (i[j])
	{
		if (i[j] == '%')
		{
			j++;
			tipo += ft_print(arg, i[j]);
		}
		else
			tipo += ft_putchar(i[j]);
		j++;
	}
	va_end(arg);
	return (tipo);
}
// va_list = type for iterating arguments
// va_start = start iterating arguments with a va_list
// va_end = free a va_list
// va_arg = Retrieve an argument
/* int main() 
 {
     int n = 123456789;
     unsigned int u_n = 234;
     char c = 'a';
     char *str = "ciao sono luca";
     void *ptr = &n;   //Puntatore a una variabile int

 	ft_printf("Carattere: %c\n", c);
 	ft_printf("Stringa: %s\n", str);
 	ft_printf("Puntatore: %p\n", ptr);
     ft_printf("Numero intero in base 10: %d\n", n);
 	ft_printf("Numero intero: %i\n", n);
     ft_printf("Numero intero senza segno: %u\n", u_n);
 	ft_printf("Numero intero in esadecimale minuscolo: %x\n", n);
 	ft_printf("Numero intero in esadecimale maiuscolo: %X\n", n);
 	ft_printf("percentuale: %%\n");
     return (0);
 }*/