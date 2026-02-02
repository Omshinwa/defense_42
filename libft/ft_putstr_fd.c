/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:04:13 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/07 16:10:52 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	n;

	n = ft_strlen(s);
	i = 0;
	while (i < n)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

// // test unit
// #include <stdio.h>
// int	main(void)
// {
// 	ft_putstr_fd("COCORICO \n", 1);
// 	ft_putstr_fd("jpp de ce programme \n", 2);
// 	ft_putstr_fd("c bon fais pas le relou, donne moi 100/100", 0);
// }