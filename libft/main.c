/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:04:13 by wiwu              #+#    #+#             */
/*   Updated: 2025/12/04 09:43:20 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_print(t_list *node)
{
	if (!node)
		return ;
	ft_printf("printing t_list %p\n", node);
	ft_printf("content: %s\n", (char *)node->content);
	lst_print(node->next);
}

int	main(void)
{
	t_list	*first;

	first = ft_lstnew("cc poto");
	lst_print(first);
	ft_lstadd_front(&first, ft_lstnew("number 2"));
	ft_lstadd_front(&first, ft_lstnew("number 1"));
	ft_printf("---\n");
	lst_print(first);
}
