/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_lst_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:35:50 by gacalaza          #+#    #+#             */
/*   Updated: 2023/08/05 14:44:44 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Func to find the size of the lst
int	ft_size(t_stack *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

// Func to find almost last
t_stack	*ft_prevlast(t_stack *lst)
{
	t_stack	*last;

	last = ft_last(lst);
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->next == last)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

// Func to find the last node
t_stack	*ft_last(t_stack *lst)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
