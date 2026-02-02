/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:42:52 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/12 17:01:24 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*s2;

	s2 = s;
	i = 0;
	while (i < n)
	{
		s2[i] = c;
		i++;
	}
	return (s);
}

// #include <string.h>
// #include <stdio.h>
// #define REFF memset
// #define FUNC ft_memset
// int	main(void)
// {
// 	int	cc;
// 	cc = 1; // dummy value, just to create a mem address
// 	printf("%d \n", cc);
// 	FUNC(&cc, 2, 4);
// 	// this set the value to 00000010 00000010 00000010 00000010
// 	printf("%d \n", cc); // 33686018
// 	REFF(&cc, 2, 4);
// 	printf("%d \n", cc); // 33686018
// }