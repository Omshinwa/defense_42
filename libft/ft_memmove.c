/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:42:52 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/12 17:07:03 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest2;
	const char	*src2;

	if (!dest && !src)
		return (NULL);
	dest2 = (char *)dest;
	src2 = (const char *)src;
	if (src >= dest)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			dest2[n - 1] = src2[n - 1];
			n--;
		}
	}
	return (dest);
}

// #include <string.h>
// #include <stdio.h>
// #define FUNC ft_memmove
// #define REFF memmove
// int	main(void)
// {
// 	char	cc[3] = "cde";
// 	char	*dd;
// 	dd = cc - 2;
// 	*dd = 'a';
// 	*(dd+1) = 'b';
// 	printf("dest: %s \n", dd); //abcde
// 	FUNC(cc, dd, 3);
// 	printf("dest: %s \n", dd); //ababc
// }