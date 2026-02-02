/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:25:23 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/12 16:46:04 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	i = 0;
	if (n <= 0)
		return (0);
	while (i < n - 1 && p1[i] == p2[i])
		i++;
	if (i == n)
		return (0);
	return (p1[i] - p2[i]);
}

// #include <stdio.h>
// #include <string.h>
// #define FUNC ft_memcmp
// #define REFF memcmp
// int	main(void)
// {
// 	printf("%d\n", REFF("abcdef", "abcdee", 5)); // 0
// 	printf("%d\n", FUNC("abcdef", "abcdee", 5)); // 0
// 	printf("%d\n", REFF("", "", 5)); // 0
// 	printf("%d\n", FUNC("", "", 5)); // 0
// 	printf("%d\n", REFF("0bcdef", "3bcdee", -5)); // neg
// 	printf("%d\n", FUNC("0bcdef", "3bcdee", -5)); // neg
// }