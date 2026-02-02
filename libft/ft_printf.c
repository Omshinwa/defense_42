/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:37:09 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/17 17:50:19 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Program name 	libftprintf.a
// Turn in files	Makefile, *.h, */*.h, *.c, */*.c
// Makefile			NAME, all, clean, fclean, re
// External functs.	malloc, free, write,
// 					va_start, va_arg, va_copy, va_end
// Libft authorized	Yes
// Description		Write a library that contains ft_printf(), a
//					function that will mimic the original printf()

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static int	print_unsigned(unsigned long nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
		count += print_unsigned(nbr / 10);
	count += print_char('0' + (nbr % 10));
	return (count);
}

static int	print_nbr(int n)
{
	int				count;
	unsigned int	n_unsigned;

	count = 0;
	n_unsigned = (unsigned int) n;
	if (n < 0)
	{
		count += print_char('-');
		n_unsigned = -n_unsigned;
	}
	if (n_unsigned >= 10)
		count += print_nbr(n_unsigned / 10);
	count += print_char(n_unsigned % 10 + '0');
	return (count);
}

static int	process_char(char c, va_list arg)
{
	if (c == '%')
		return (print_char('%'));
	if (c == 'c')
		return (print_char((char)va_arg(arg, int)));
	if (c == 'd' || c == 'i')
		return (print_nbr(va_arg(arg, int)));
	if (c == 's')
		return (print_str(va_arg(arg, char *)));
	if (c == 'p')
		return (print_address(va_arg(arg, void *)));
	if (c == 'u')
		return (print_unsigned(va_arg(arg, unsigned int)));
	if (c == 'x')
		return (print_hex((unsigned int) va_arg(arg, int), 0));
	if (c == 'X')
		return (print_hex((unsigned int) va_arg(arg, int), 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	if (!str)
		return (-1);
	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] != '%')
			count += print_char(str[i]);
		else
		{
			i++;
			count += process_char(str[i], arg);
		}
		i++;
	}
	va_end(arg);
	return (count);
}

// int main(void)
// {
// 	int 	ptr[] = {55};
// 	int		res;
// 	ft_printf("----------TESTING UNIT----------\n");
// 	printf("-- Testing reading NULL return value\n");
// 	res = printf(NULL); 
// 	printf("res: %d\n", res);		// res: -1
// 	res = ft_printf(NULL);
// 	printf("res: %d\n", res);		// res: -1
// 	printf("-- Testing reading %%%%%%\n");
// 	res = printf("%%%%%%\n");		// %%%
// 	printf("res: %d\n", res);		// res: 4
// 	res = ft_printf("%%%%%%\n");	// %%%
// 	printf("res: %d\n", res);		// res: 4
// 	printf("-- Testing reading %%%%%%1 \n");
// 	printf("%%%%%%%d\n", 1);	// %%%1
// 	ft_printf("%%%%%%%d\n", 1);	// %%%1
// 	printf("-- Testing reading same pointer \n");
// 	printf("%p \n", ptr);		// should be the same pointer
// 	ft_printf("%p \n", ptr);	// should be the same pointer
// 	printf("-- Testing reading -9 with %%i \n");
// 	res = printf("%i \n", -9);
// 	printf("res: %i\n", res);
// 	res = ft_printf("%i \n", -9);
// 	printf("res: %i\n", res);
// 	printf("-- Testing reading -9 with %%d \n");
// 	printf("%d \n", -9);
// 	ft_printf("%d \n", -9);
// 	printf("-- Testing reading -9 with %%u \n");
// 	printf("%u \n", -9);
// 	ft_printf("%u \n", -9);
// 	printf("-- Testing reading -9 with %%x \n");
// 	printf("%x \n", -9);
// 	ft_printf("%x \n", -9);
// 	printf("-- Testing reading -9 with %%X \n");
// 	printf("%X \n", -9);
// 	ft_printf("%X \n", -9);
// 	printf("-- Testing a mix\n");
// 	res = printf("%s %c %%%% %i %d \n", "Hello world", 'H', 10, 101);
// 	printf("res: %i\n", res);
// 	res = ft_printf("%s %c %%%% %i %d \n", "Hello world", 'H', 10, 101);
// 	printf("res: %i\n", res);
// }