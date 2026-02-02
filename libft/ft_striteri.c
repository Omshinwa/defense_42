/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:04:13 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/11 12:57:45 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Safety concerns:
// check that f strictly modify the char for another char
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	n;

	n = ft_strlen(s);
	i = 0;
	while (i < n)
	{
		(*f)(i, &(s[i]));
		i++;
	}
}

// // test unit
// // erase 1 letter out of 2
// #include <stdio.h>
// void test_f(unsigned int i, char *s)
// {
// 	printf("%d: %c \n", i, *s);
// 	if (i % 2)
// 		*s = '_';
// }
// int	main(void)
// {
// 	char original[] = "salut la terre";
// 	// IMPORTANT!
// 	// define as array, not pointer
// 	// *original = is unmodifiable (read only)
// 	// string literal
// 	ft_striteri(original, test_f);
// 	printf("result: %s \n", original);
// }