/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:45:00 by gacalaza          #+#    #+#             */
/*   Updated: 2023/08/05 17:01:36 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap_ab(t_stack **head, int check)
{
	t_stack	*first;
	t_stack	*second;

	if (*head == NULL || (*head)->next == NULL \
			|| ft_size(*head) < 2)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (first->next != NULL)
		first->next->prev = first;
	*head = second;
	if (check == 97)
		ft_putstr_fd("sa\n", 1);
	if (check == 98)
		ft_putstr_fd("sb\n", 1);
}

// ss : sa and sb at the same time.
void	ft_swap_ss(t_stack **a_head, t_stack **b_head, int check)
{
	t_stack	*ptr;
	int		nbr;

	if (*a_head == NULL || (*a_head)->next == NULL \
			|| ft_size(*a_head) < 2)
		return ;
	if (*b_head == NULL || (*b_head)->next == NULL \
			|| ft_size(*b_head) < 2)
		return ;
	ptr = *a_head;
	nbr = ptr->nbr;
	ptr->nbr = ptr->next->nbr;
	ptr->next->nbr = nbr;
	ptr = *b_head;
	nbr = ptr->nbr;
	ptr->nbr = ptr->next->nbr;
	ptr->next->nbr = nbr;
	if (check == 195)
		ft_putstr_fd("ss\n", 1);
}
