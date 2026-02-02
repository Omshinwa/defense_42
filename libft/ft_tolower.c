/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:42:52 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/05 10:59:18 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>
// #define FUNC tolower
// int	main(void)
// {
// 	printf("%c \n", FUNC('5'));
// 	printf("%c \n", FUNC('Q'));
// 	printf("%c \n", FUNC('e'));
// }