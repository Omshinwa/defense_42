/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:42:52 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/12 17:07:12 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*s1;
	const char	*s2;

	if (!dest && !src)
		return (NULL);
	s1 = (char *)dest;
	s2 = (const char *)src;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}

// #include <string.h>
// #include <stdio.h>
// #define FUNC ft_memcpy
// int	main(void)
// {
// 	int	cc;
// 	int	dd;
// 	cc = 1;
// 	dd = 99;
// 	printf("%d \n", cc);
// 	FUNC(&cc, &dd, 4);
// 	printf("%d \n", cc);
// }