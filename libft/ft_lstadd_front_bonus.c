/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:04:13 by wiwu              #+#    #+#             */
/*   Updated: 2025/12/04 13:30:59 by wiwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function Name ft_lstadd_front
// Prototype void ft_lstadd_front(t_list **lst, t_list *new);
// Files to Submit -
// Parameters lst: The address of a pointer to the first node of
// a list.
// new: The address of a pointer to the node to be
// added.
// Return Value None
// External Function None
// Description Adds the node ’new’ at the beginning of the list.

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
