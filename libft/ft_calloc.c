/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:25:23 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/13 15:15:06 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmemb > ((size_t) -1 / size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// #include <stdio.h>
// #include <stdlib.h>
// #define FUNC calloc
// int	main(void)
// {
// 	char *ptr;
// 	char *ptr2;
// 	ptr = (char*)calloc(5, 5);
// 	ptr2 = ptr;
// 	printf("ORIGINAL POSITION %p %d\n", ptr, ptr);
// 	while(!(*ptr))
// 		ptr++;
// 	printf("FIRST NON NUL POSITION %p %d\n", ptr, ptr);
// 	printf("DIFF %d\n", ptr2-ptr);
// }
