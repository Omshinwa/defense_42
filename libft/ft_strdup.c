/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:25:23 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/13 12:11:57 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		i;
	int		len;

	len = ft_strlen(s);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	char	*string1;
// 	char	*string2;

// 	string1 = "hello world";
// 	printf("%s\n", string1);
// 	string2 = ft_strdup(string1);
// 	printf("%s\n", string2);
// 	string1 = "can i realloc?";
// 	printf("%s\n", string1);
// 	printf("%s\n", string2);

// 	char *str = "lorem ipsum dolor sit amet";
// 	char *str_dup;
// 	if (!(str_dup = ft_strdup(str)))
// 		printf("NULL \n");
// 	else
// 		printf("%s \n", str_dup);
// 	if (str_dup == str)
// 		printf("\nERROR: str_dup's adress == str's adress");
// }