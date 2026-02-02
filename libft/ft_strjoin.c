/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:31:06 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/10 13:38:26 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	n;

	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(n);
	if (!res)
		return (NULL);
	*res = '\0';
	ft_strlcat(res, s1, n);
	ft_strlcat(res, s2, n);
	return (res);
}

// #include <stdio.h>
// int	main(void)
// {
// 	// char	*strs[] = {"Hello", " World"};
// 	// char	*strs2[] = {"les cas ","particuliers"};
// 	// printf("%s \n", ft_strjoin(strs[0], strs[1]));
// 	// printf("%s \n", ft_strjoin(strs2[0], strs2[1]));
// 	printf("%s \n", ft_strjoin("lorem ipsum", "dolor sit amet"));
// 	printf("%s \n", ft_strjoin("", "dolor sit amet"));
// 	printf("%s \n", ft_strjoin("lorem ipsum", ""));
// }