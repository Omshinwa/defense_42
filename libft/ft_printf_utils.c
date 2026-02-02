/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:37:09 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/16 22:30:52 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (print_str("(null)"));
	while (*str)
	{
		count += print_char(*str);
		str++;
	}
	return (count);
}

static int	print_hex_long(unsigned long address)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (address >= 16)
		count += print_hex_long(address / 16);
	count += (print_char(base[address % 16]));
	return (count);
}

int	print_address(void *ptr)
{
	if (ptr)
	{
		print_str("0x");
		return (2 + print_hex_long((unsigned long) ptr));
	}
	else
		return (print_str(("(nil)")));
}

int	print_hex(unsigned int nbr, int is_upper)
{
	int	count;
	int	rest;

	count = 0;
	if (nbr >= 16)
		count += (print_hex(nbr / 16, is_upper));
	rest = nbr % 16;
	if (rest <= 9)
		count += print_char(rest + '0');
	else
	{
		if (is_upper)
			count += print_char('A' + rest - 10);
		else
			count += print_char('a' + rest - 10);
	}
	return (count);
}
