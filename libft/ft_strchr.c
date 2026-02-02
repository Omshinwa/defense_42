/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:13:09 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/13 12:11:51 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *)s + i);
	return (NULL);
}

// int	main(void)
// {
// 	char var1[] = "Hello World";
// 	char var2 = 'e';
// // @ uc = (unsigned char)c;
// 	printf("\n******\n");
// 	printf("%s\n", REFF(var1, var2)); // Hello World
// 	printf("%s\n", FUNC(var1, var2)); // Hello World
// 	printf("%s\n", REFF(var1, ' ')); // Hello World
// 	printf("%s\n", FUNC(var1, ' ')); // Hello World
// 	printf("%s\n", REFF(var1, 'w')); // Hello World
// 	printf("%s\n", FUNC(var1, 'w')); // Hello World
// }
