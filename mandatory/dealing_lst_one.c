/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_lst_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:45:51 by gacalaza          #+#    #+#             */
/*   Updated: 2023/08/05 17:00:15 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Func to create a new node
t_stack	*createnode(int nbr, int index)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (!newnode)
		ft_puterror();
	newnode->nbr = nbr;
	newnode->index = index;
	newnode->next = NULL;
	return (newnode);
}

// Func to add node at the beging of the lst
void	ft_add_front(t_stack **lst, t_stack *new)
{
	if (*lst)
	{
		new->next = *lst;
		new->prev = NULL;
		*lst = new;
	}
	else
		*lst = new;
}

// Func to add node at the end of the lst
void	ft_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (*lst)
	{
		temp = ft_last(*lst);
		temp->next = new;
		new->prev = temp;
	}
	else
		if (*lst)
			*lst = new;
}

// Func to free the the lst
void	ft_clear(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*next;

	temp = *lst;
	while (temp != NULL)
	{
		next = temp->next;
		free (temp);
		temp = next;
	}
	*lst = NULL;
}
