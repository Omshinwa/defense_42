/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:42:52 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/05 10:56:24 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c + 'A' - 'a');
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>
// #define FUNC ft_toupper
// int	main(void)
// {
// 	printf("%c \n", FUNC('5'));
// 	printf("%c \n", FUNC('Q'));
// 	printf("%c \n", FUNC('e'));
// }