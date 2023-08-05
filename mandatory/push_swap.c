/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:46:43 by gacalaza          #+#    #+#             */
/*   Updated: 2023/08/05 17:00:44 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		len;

	a = NULL;
	b = NULL;
	if (check_args(argc, argv))
		a = starting(&a, argc, argv);
	len = ft_size(a);
	if (len > 1 && !check_its_sorted_a(&a))
		sorting_it(&a, &b, len);
	ft_clear(&a);
	ft_clear(&b);
	return (0);
}
