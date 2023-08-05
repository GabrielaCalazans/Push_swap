/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:27:45 by gacalaza          #+#    #+#             */
/*   Updated: 2023/08/05 17:00:30 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_atoi_error(const char *nptr)
{
	long	result;
	int		count;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while ((nptr[count] >= 9 && nptr[count] <= 13) || nptr[count] == 32)
		count++;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			sign = -1;
		count++;
	}
	while (nptr[count] != '\0' && ft_isdigit(nptr[count]))
	{
		result = (result * 10) + (nptr[count] - '0');
		count++;
	}
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
		ft_puterror();
	return (result * sign);
}

void	push_all_b_to_a(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_size(*b);
	while (len > 0)
	{
		ft_push_a(a, b, 97);
		len--;
	}
}

// Func checks if the stack is sorted.
int	check_its_sorted_a(t_stack **head)
{
	int		i;
	t_stack	*temp;

	temp = *head;
	i = temp->index;
	while (temp)
	{
		if (i > temp->index)
			return (0);
		i = temp->index;
		temp = temp->next;
	}
	return (1);
}
