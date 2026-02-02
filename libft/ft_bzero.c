/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:42:52 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/12 14:07:31 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// #include <string.h>
// #include <stdio.h>
// #define REFF bzero
// #define FUNC ft_bzero
// int	main(void)
// {
// 	int cc[6] = {1, 2, 3, 4, 5, 6};
// 	printf("original: %d \n", *cc);
// 	FUNC(cc, 20);
// 	printf("%d \n", *cc);  // 0
// 	printf("%d \n", *(cc+1)); // 0
// 	printf("%d \n", *(cc+2)); // 0
// 	printf("%d \n", *(cc+3)); // 0
// 	printf("%d \n", *(cc+4)); // 0
// 	printf("%d \n", *(cc+5)); // 6
// }