/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:13:09 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/07 19:39:50 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// the return value allows to check if we went outside the range
static size_t	is_b_in_a(const char *A, const char *B)
{
	size_t	i;

	i = 0;
	while (B[i])
	{
		if (B[i] != A[i])
			return (0);
		i++;
	}
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	end_index;

	i = 0;
	(void) len;
	if (*little == 0)
		return ((char *)big + i);
	while (i < len && big[i])
	{
		end_index = is_b_in_a(big + i, little);
		if (end_index + i > len)
			return (NULL);
		if (end_index)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

// #include <bsd/string.h>
// #include <stdio.h>
// #define REFF strnstr
// #define FUNC ft_strnstr

// int	main(void)
// {
// 	char var1[] = "Hello World";
// 	char var2[] = " ";
// 	char var3[] = "o";
// 	char var4[] = " ";
// 	char var5[] = "";
// 	char var6[] = ".";

// 	printf("\n******\n");
// 	printf("%s\n", REFF(var1, var2, 1)); // Hello World
// 	printf("%s\n", FUNC(var1, var2, 1)); // Hello World
// 	printf("%s\n", REFF(var1, var2, 0)); // Hello World
// 	printf("%s\n", FUNC(var1, var2, 0)); // Hello World
// 	printf("%s\n", REFF(var1, var2, -1)); // Hello World
// 	printf("%s\n", FUNC(var1, var2, -1)); // Hello World

// 	printf("%s\n", REFF("lorem ipsum dolor sit amet", "dolor", 15));
// 	printf("%s\n", FUNC("lorem ipsum dolor sit amet", "dolor", 15));
// }
