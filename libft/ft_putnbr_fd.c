/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:04:13 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/13 16:36:15 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	write(fd, &"0123456789"[nbr % 10], 1);
}

// // test unit
// #include <stdio.h>
// #include <unistd.h>
// int	main(void)
// {
// 	ft_putnbr_fd(5656, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-696969, 2);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(0, 0);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-2147483648, 0);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-2147483647, 0);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-0, 0);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(2147483647, 0);
// }