/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:29:03 by gacalaza          #+#    #+#             */
/*   Updated: 2023/08/05 17:00:35 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// ** Func finds and returns the smallest nbr int int the stack
int	ft_min(t_stack *head)
{
	int		min;

	min = head->index;
	while (head)
	{
		if (head->index < min)
			min = head->index;
		head = head->next;
	}
	return (min);
}

// ** Func finds and returns the biggest nbr int in the stack
int	ft_max(t_stack *head)
{
	int		max;

	max = head->index;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	return (max);
}

// ** Func finds and returns the position of the smallest nbr int int the stack
int	ft_int_pos(t_stack *head, int find)
{
	int	pos;

	pos = 0;
	while (head)
	{
		if (head->index == find)
			return (pos);
		head = head->next;
		pos++;
	}
	return (pos);
}
