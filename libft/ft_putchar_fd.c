/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:04:13 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/07 16:06:44 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// // test unit
// #include <stdio.h>
// int	main(void)
// {
// 	ft_putchar_fd('c', 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putchar_fd('Q', 2);
// 	ft_putchar_fd('Q', 0);
// }