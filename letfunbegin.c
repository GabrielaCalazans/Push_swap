/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letfunbegin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/07/28 14:19:13 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sorting_it(t_stack **a, t_stack **b, int len)
{
	if (len == 2)
		sort_three(a, 97);
	if (len >= 3 && len <= 4)
		sort_three(a, 97);
	if (len == 5)
		sort_five(a, b, len);
	// if (len < 11)
	// 	sort_five2(a, b, len);
	if (len > 5)
		sort_hundred(a, b);
}

void	sort_three(t_stack **a, int check)
{
	if (check_its_sorted_a(a) && check == 97)
		return ;
	if (ft_min(*a) == (*a)->index)
	{
		ft_swap_ab(a, check);
		ft_rotate_ab(a, check);
	}
	else if (ft_max(*a) == (*a)->index)
	{
		ft_rotate_ab(a, check);
		if (!check_its_sorted_a(a) && check == 97)
			ft_swap_ab(a, check);
	}
	else
	{
		printf("HERE SORT3\n");
		ft_swap_ab(a, check);
		sort_three(a, check);
	}
}

void	sort_three_b(t_stack **b, int check)
{
	if (check_its_sorted_b(b) && check == 98)
		return ;
	if (ft_max(*b) == (*b)->index)
	{
		ft_swap_ab(b, check);
		ft_rotate_ab(b, check);
	}
	else if (ft_min(*b) == (*b)->index)
	{
		ft_rotate_ab(b, check);
		if (!check_its_sorted_b(b) && check == 97)
			ft_swap_ab(b, check);
	}
	else
	{
		ft_swap_ab(b, check);
		sort_three(b, check);
	}
}

void	sort_five(t_stack **a, t_stack **b, int size)
{
	int	pos;

	if (check_its_sorted_a(a) && size == ft_size(*a))
		return ;
	pos = ft_int_pos(*a, ft_min(*a));
	if (pos == size)
		ft_rev_rotate_ab(a, 97);
	else if (ft_min(*a) == (*a)->index)
		ft_push_b(a, b, 98);
	else if ((*a)->index > (*a)->next->index && pos > size / 2)
		ft_swap_ab(a, 97);
	else if (pos <= size / 2)
		ft_rotate_ab(a, 97);
	else
		ft_rev_rotate_ab(a, 97);
	if (check_its_sorted_a(a))
	{
		push_all_b_to_a(a, b);
		return ;
	}
	else
		sort_five(a, b, size);
}

void	sort_hundred_a_to_b(t_stack **a, t_stack **b)
{
	if (!check_its_sorted_a(a) && ft_size(*a) > 3)
		ft_push_b(a, b, 98);
	if (!check_its_sorted_a(a) && ft_size(*a) > 3)
		ft_push_b(a, b, 98);
	if (!check_its_sorted_a(a) && ft_size(*a) > 3)
	{
		ft_push_b(a, b, 98);
		sort_three_b(b, 98);
	}
	if (!check_its_sorted_a(a) && ft_size(*a) > 3)
		check_and_push_to_b(a, b);
	if (!check_its_sorted_a(a) && ft_size(*a) == 3)
		sort_three(a, 97);
}

void	check_and_push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		i;

	while (ft_size(*a) > 3 && !check_its_sorted_a(a))
	{
		temp = *a;
		i = check_op_a_to_b(*a, *b);
		while (i >= 0)
		{
			if (i == check_single_rot_atob(*a, *b, temp->index))
				i = do_single_rot_atob(a, b, temp->index, 97);
			else if (i == check_double_revrot_atob(*a, *b, temp->index))
				i = do_double_revrot_atob(a, b, temp->index, 97);
			else if (i == check_rota_revrotb_atob(*a, *b, temp->index))
				i = do_rota_revrotb(a, b, temp->index, 97);
			else if (i == check_rotb_revrota_atob(*a, *b, temp->index))
				i = do_rotb_revrota(a, b, temp->index, 97);
			else
				temp = temp->next;
		}
	}
}

void	check_and_push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		i;

	temp = *b;
	while (temp != NULL)
	{
		temp = *b;
		i = check_op_b_to_a(*a, *b);
		printf("i:%i", i);
		while (i >= 0)
		{
			if (i == rate_rr_btoa(*a, *b, temp->index))
				i = do_single_rot_atob(a, b, temp->index, 98);
			else if (i == rate_rrr_btoa(*a, *b, temp->index))
				i = do_double_revrot_atob(a, b, temp->index, 98);
			else if (i == rate_ra_rrb_btoa(*a, *b, temp->index))
				i = do_rota_revrotb(a, b, temp->index, 98);
			else if (i == rate_rb_rra_btoa(*a, *b, temp->index))
				i = do_rotb_revrota(a, b, temp->index, 98);
			else
				temp = temp->next;
			printf("i:%i", i);
		}
		printf("HERE CHECKANDPUSH TO A\n");
	}
}

void	sort_final(t_stack **a)
{
	int	pos_min;
	int	size;
	int	pos_final;

	size = ft_size(*a) / 2;
	pos_min = ft_int_pos(*a, ft_min(*a));
	pos_final = size - pos_min;
	if (pos_min < size)
	{
		while (pos_min-- > 0)
			ft_rotate_ab(a, 97);
	}
	else if (pos_min > size)
	{
		while (pos_final > 0)
		{
			ft_rev_rotate_ab(a, 97);
			pos_final--;
		}
	}
}

void	sort_hundred(t_stack **a, t_stack **b)
{
	if (!check_its_sorted_a(a) && ft_size(*a) > 3)
		sort_hundred_a_to_b(a, b);
	if (!check_its_sorted_a(a) && ft_size(*a) == 3)
		sort_three(a, 97);
	if (ft_size(*b) > 3)
		check_and_push_to_a(a, b);
	if (!check_its_sorted_a(a) && !b)
		sort_final(a);
}
