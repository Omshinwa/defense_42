/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:25:23 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/07 19:20:22 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (i < n - 1 && s1[i] && s2[i]
		&& (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	if ((unsigned char)s1[i] == (unsigned char)s2[i])
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>
// #include <string.h>
// #define FUNC ft_strncmp
// int	main(void)
// {
// 	// printf("%d\n", FUNC("abcdef", "abcdee", 5));
// 	// printf("%d\n", FUNC("0bcdef", "0bcdee", -5));
// 	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
// 	printf("%d\n", strncmp("test\200", "test\0", 6));
// }
