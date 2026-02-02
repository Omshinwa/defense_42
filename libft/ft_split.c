/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:04:13 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/13 12:11:39 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;
	int	at_least_one_w;

	i = 0;
	count = 0;
	at_least_one_w = 0;
	if (*str && *str != c)
		at_least_one_w = 1;
	while (str[i] && str[i + 1])
	{
		if (str[i] == c && str[i + 1] != c)
			count++;
		i++;
	}
	return (count + at_least_one_w);
}

static void	free_array(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// Return 0 on malloc error, 1 on success
static int	populate_array(char const *str, char c, char **arr, size_t arr_i)
{
	size_t		end;
	size_t		start;

	end = 0;
	start = 0;
	while (end < ft_strlen(str) + 1)
	{
		if (str[end] == c || str[end] == '\0')
		{
			while (str[start] == c && end > start)
				start++;
			if (end > start)
			{
				arr[arr_i] = ft_substr(str, start, end - start);
				if (!arr[arr_i])
					return (0);
				arr_i++;
			}
			start = end;
		}
		end++;
	}
	arr[arr_i] = NULL;
	return (1);
}

// Initialize and check for bad input
char	**ft_split(char const *str, char c)
{
	char	**arr;
	size_t	arr_i;

	arr_i = 0;
	if (!str)
		return (NULL);
	arr = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!arr)
		return (NULL);
	if (!populate_array(str, c, arr, arr_i))
	{
		free_array(arr);
		return (NULL);
	}
	return (arr);
}

// #include <string.h>
// #include <stdio.h>
// #include <unistd.h>
// // // test exact size
// int	main(void)
// {
// 	char * * tab = ft_split("  trip  42  ", ' ');
// 	printf("%s\n", *tab); // trip
// 	printf("%s\n", *(tab+1)); // 42
// 	printf("%s\n", *(tab+2)); // (null)
// 	// printf("%s\n", *(tab+3)); // - should crash
// 	// printf("%s\n", *(tab+4)); // -
// 	// printf("%s\n", *(tab+5)); // -
//
// 	printf("testing '' and ' ' \n");
//
// 	tab = ft_split("", ' ');
// 	printf("%s\n", *tab); // (null)
// 	printf("%s\n", *tab+1); // - should crash
// 	printf("%s\n", *tab+2); // - should crash
//	// possible improv: on fail of ft_substr, free the whole array
//	//	return NULL
// }
