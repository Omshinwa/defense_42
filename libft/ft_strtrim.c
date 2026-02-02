/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:04:13 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/13 12:12:48 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function Name	ft_strtrim
// Prototype		char *ft_strtrim(char const *s1, char const *set);
// Files to Submit	-
// Parameters		s1: The string to be trimmed.
//					set: The string containing the set of characters
//					to be removed.
// Return Value		The trimmed string.
//					NULL if the allocation fails.
// External Function malloc
// Description 		Allocates memory (using malloc(3)) and returns a
//					copy of ’s1’ with characters from ’set’ removed
//					from the beginning and the end.

#include "libft.h"

static int	include(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	while (s1[start] && include(s1[start], set))
		start++;
	if (s1[start] == '\0')
		return (ft_substr(s1, 0, 0));
	end = ft_strlen(s1) - 1;
	while (end > start && include(s1[end], set))
		end--;
	len = end - start + 1;
	return (ft_substr(s1, start, len));
}

// // test unit
// #include <stdio.h>
// #define FUNCTION ft_strtrim
// int	main(void)
// {
// 	// printf("%d \n", include('a', "aA"));
// 	printf("%s \n", FUNCTION("aAaaSSAaAA", "aA"));
// 	// printf("%s \n", FUNCTION("aaaa", "a"));
// 	// printf("%s \n", FUNCTION("$$$e", "e$"));
// 	// printf("%s \n", FUNCTION("$$$e", "e"));
// 	// printf("%s \n", FUNCTION("-aaaa----", "-"));
// 	// char *test_free = FUNCTION("-aaaa----", "-");
// 	// free(test_free);
// 	// test_free = FUNCTION("", "");
// 	// printf("%s \n", test_free);
// 	// free(test_free);
// }