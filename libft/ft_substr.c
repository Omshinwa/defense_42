/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:04:13 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/27 12:53:10 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function Name ft_substr
// Prototype char *ft_substr(char const *s, unsigned int start,
// size_t len);
// Files to Submit -
// Parameters s: The original string from which to create the
// substring.
// start: The starting index of the substring within
// ’s’.
// len: The maximum length of the substring.
// Return Value The substring.
// NULL if the allocation fails.
// External Function malloc
// Description
// Allocates memory (using malloc(3)) and returns a
// substring from the string ’s’.
// The substring starts at index ’start’ and has a
// maximum length of ’len’.

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			i;
	unsigned int	len_s;

	i = 0;
	len_s = ft_strlen(s);
	while (len_s > start && s[i + start] && i < len)
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (len_s > start && s[i + start] && i < len)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = 0;
	return (res);
}

// // test unit
// #include <stdio.h>
// int	main(void)
// {
// 	// char *s = "SAlut mes poulettes";

// 	// printf("%s \n", ft_substr(s, 0, 1));
// 	// printf("%s \n", ft_substr(s, 0, 2));
// 	// printf("%s \n", ft_substr(s, 1, 2));
// 	// printf("%s \n", ft_substr(s, 2, 10));
// 	// printf("%s \n", ft_substr(s, 5, 30));

// 	// printf("%s \n", ft_substr("lorem ipsum dolor sit amet", 0, 10));

// 	// printf("%s \n", ft_substr("", 1, 5));
// 	printf("%s", ft_substr("salut", 10, 1));
// }