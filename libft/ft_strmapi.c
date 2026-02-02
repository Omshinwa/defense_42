/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:04:13 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/27 12:54:29 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function Name	
// ft_strmapi
// Prototype
// char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
// Parameters
// s: The string to iterate over.
// f: The function to apply to each character.
// Return Value
// The string created from the successive applications of ’f’.
// Returns	NULL if the allocation fails.
// External Function - malloc
// Description 
// Applies the function f to each character of the
// string s, passing its index as the first argument
// and the character itself as the second. A new
// string is created (using malloc(3)) to store the
// results from the successive applications of f.

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

// // test unit
// // erase 1 letter out of 2
// #include <stdio.h>
// char test_f(unsigned int i, char s)
// {
// 	if (i % 2)
// 		return ('_');
// 	return (s);
// }
// int	main(void)
// {
// 	printf("result: %s \n", ft_strmapi("salut la terre", &test_f));
// }