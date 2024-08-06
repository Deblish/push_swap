/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:08:35 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/06 09:36:32 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_stack *a, t_stack *b)
{
	if (is_ordered(a, 0))
		return ;
	if (a->size == 3 || a->size == 2)
	{
		sort_three_a(a);
		return ;
	}
	if (a->size >= 4)
		pb(a, b);
	if (a->size >= 5)
		pb(a, b);
	while (a->size > 3)
		do_cheapest_a_to_b(a, b);
	sort_three_a(a);
	while (b->size)
		do_move_b_to_a(a, b);
	while (!is_ordered(a, 0))
		rra(a);
}
