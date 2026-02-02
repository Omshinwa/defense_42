/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:42:52 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/12 16:08:35 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

// #include <stdio.h>
// #define FUNC ft_isalnum
// int	main(void)
// {
// 	printf("%d \n", FUNC('5'));
// 	printf("%d \n", FUNC('Q'));
// 	printf("%d \n", FUNC('@'));
// 	printf("%d \n", FUNC('#'));
// 	printf("%d \n", FUNC('n'));
// 	printf("%d \n", FUNC(0));
// }