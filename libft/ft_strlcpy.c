/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:13:45 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/13 12:12:19 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{	
	size_t	i;

	i = 0;
	if (len == 0)
		return (ft_strlen(src));
	while (src[i] && i < len - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

// #include <bsd/string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	dest[12] = "Hello";
// 	char	*src = " world";

// 	printf("\n******\n");
// 	printf("%d\n", ft_strlcpy(dest, src, 1));
// 	printf("%s\n", dest);
// 	printf("%d\n", strlcpy(dest, src, 1));
// 	printf("%s\n", dest);
// }