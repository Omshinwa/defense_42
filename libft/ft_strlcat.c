/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:13:09 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/10 13:23:25 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// concatenate src to the end of dest
// size is the size of the new dest
// doesnt do anything if size <= len(dest)
// If return value >= siz, truncation occurred.
// if size = 1, it will only copy \0
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (len_dest >= size)
		return (size + ft_strlen(src));
	while (src[i] && i < size - len_dest - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}

// #include <stdio.h>
// #include <bsd/string.h>
// int	main(void)
// {
// 	char	dest[20] = "Hello";
// 	char	*src = " world";
// 	printf("\n******\n");
// 	printf("%zu\n", strlcat(dest, src, 4));
// 	printf("%s\n", dest);
// }
