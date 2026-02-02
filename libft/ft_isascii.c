/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:42:52 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/05 08:54:35 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
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