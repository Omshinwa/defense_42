/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:04:13 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/13 13:26:57 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function Name	ft_itoa
// Prototype char	*ft_itoa(int n);
// Files to Submit -
// Parameters		n: The integer to convert.
// Return Value		The string representing the integer.
//					NULL if the allocation fails.
// External Function malloc
// Description		Allocates memory (using malloc(3)) and returns
// 					a string representing the integer received as an
// 					argument. Negative numbers must be handled.

#include "libft.h"

// we use a trick, res is full of \0, so we only overwrite those
static void	push_char(char *res, unsigned int n_unsigned)
{
	if (n_unsigned < 10)
	{
		while (*res != 0)
			res++;
		*res = '0' + n_unsigned;
	}
	else
	{
		push_char(res, n_unsigned / 10);
		push_char(res, n_unsigned % 10);
	}
}

static int	get_n_log(int n)
{
	int				len;
	unsigned int	n_unsigned;

	len = 0;
	n_unsigned = (unsigned int) n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n_unsigned = -n_unsigned;
	}
	while (n_unsigned > 0)
	{
		len++;
		n_unsigned /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*res;
	int				i;
	int				n_length;
	unsigned int	n_unsigned;

	n_length = get_n_log(n);
	res = malloc(sizeof(char) * (n_length + 1));
	n_unsigned = (unsigned int) n;
	if (!res)
		return (NULL);
	ft_bzero(res, n_length + 1);
	i = 0;
	if (n < 0)
	{
		n_unsigned = -n_unsigned;
		res[i++] = '-';
	}
	push_char(&(res[i]), n_unsigned);
	return (res);
}

// // // test unit
// #include <stdio.h>
// #define FUNCTION ft_itoa
// int	main(void)
// {
// 	printf("result: %d \n", get_n_log(0));
// 	printf("result: %s \n", FUNCTION(0));
// 	printf("result: %s \n", FUNCTION(2));
// 	printf("result: %s \n", FUNCTION(123456));
// 	printf("result: %s \n", FUNCTION(6969));
// 	printf("result: %s \n", FUNCTION(-448886));
// 	printf("result: %s \n", FUNCTION(-8));
// 	printf("result: %s \n", FUNCTION(-2147483648));
// 	printf("result: %s \n", FUNCTION(-2147483647));
// 	printf("result: %s \n", FUNCTION(-0));
// }