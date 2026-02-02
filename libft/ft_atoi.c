/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:03:11 by wiwu              #+#    #+#             */
/*   Updated: 2025/12/04 11:51:20 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	sum;
	int	sign;

	sum = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		sum *= 10;
		sum += *str - '0';
		str++;
	}
	return (sum * sign);
}

// // test unit
// #include <unistd.h>
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d \n", ft_atoi("	--+-02ewe")); // return -2
// 	printf("%d \n", ft_atoi("2-2")); // 2
// 	printf("%d \n", ft_atoi("	---2147483648")); // return 0
// 	printf("%d \n", ft_atoi("	-2147483648")); // return -2147483648
// 	printf("%d \n", ft_atoi("	21474836481")); // overflows
// 	printf("%d \n", ft_atoi("		+09ewe")); // return 9
// 	printf("%d \n", ft_atoi("   +1234ab567")); // return 1234
// 	printf("%d \n", ft_atoi(" WW")); // return 0
// 	printf("%d \n", ft_atoi(" 78W9")); // return 78
// 	printf("%d \n", ft_atoi("   1")); // return 1
// }