/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:04:13 by wiwu              #+#    #+#             */
/*   Updated: 2025/11/16 22:23:45 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	print_char(char c);
int	print_str(char *str);
int	print_address(void *ptr);
int	print_hex(unsigned int nbr, int is_upper);
int	ft_printf(const char *str, ...);

#endif