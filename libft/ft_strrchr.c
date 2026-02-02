/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:13:09 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/11 22:28:56 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (unsigned char) c)
			return ((char *)&(s[i]));
		i--;
	}
	return (NULL);
}

// #include <bsd/string.h>
// #include <stdio.h>
// #define REFF strrchr
// #define FUNC ft_strrchr

// int	main(void)
// {
// 	char var1[] = "Hello World";
// 	char var2 = 'o';

// 	printf("\n******\n");
// 	printf("%s\n", REFF(var1, var2)); // Hello World
// 	printf("%s\n", FUNC(var1, var2)); // Hello World
// 	printf("%s\n", REFF(var1, ' ')); // Hello World
// 	printf("%s\n", FUNC(var1, ' ')); // Hello World
// 	printf("%s\n", REFF(var1, 'w')); // Hello World
// 	printf("%s\n", FUNC(var1, 'w')); // Hello World
// }
