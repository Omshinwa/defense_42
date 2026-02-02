/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:13:09 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/12 16:44:19 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;
	unsigned char	c2;

	i = 0;
	s2 = (unsigned char *) s;
	c2 = (unsigned char) c;
	while (i < n)
	{
		if (s2[i] == c2)
			return (s2 + i);
		i++;
	}
	return (NULL);
}

// #include <bsd/string.h>
// #include <stdio.h>
// #define REFF memchr
// #define FUNC ft_memchr

// int	main(void)
// {
// 	char var1[] = "Hello World";
// 	char var2 = 'e';

// 	printf("\n******\n");
// 	printf("%s\n", (char*)REFF(var1, var2, 2)); // ello World
// 	printf("%s\n", (char*)FUNC(var1, var2, 2)); // ello World
// 	printf("%s\n", (char*)REFF(var1, ' ', 8)); //  World
// 	printf("%s\n", (char*)FUNC(var1, ' ', 8)); //  World
// 	printf("%s\n", (char*)REFF(var1, 'w', 10000)); // this returns
// 	printf("%s\n", (char*)FUNC(var1, 'w', 10000)); // something after
// }
