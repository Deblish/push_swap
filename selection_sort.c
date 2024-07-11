/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:34:44 by aapadill          #+#    #+#             */
/*   Updated: 2024/07/08 16:07:43 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	low_extractor(t_stack *a, t_stack *b)
{
	//ft_printf("I entered");
	t_node	*i;
	t_node	*low;
	size_t moves;

	i = a->top;
	low = i;
	moves = 0;
	while(i->next)
	{
		i = i->next;
		moves++;
		if (i->value < low->value)
			low = i;
	}
	if (low == a->top)
	{
		pb(a,b);
		return ;
	}
	if (low == i)
	{
		rra(a);
		pb(a,b);
		return ;
	}
	if (a->size > 1 && low == a->top->next)
	{
		sa(a);
		pb(a,b);
		return ;
	}
	if (moves <= a->size / 2)
	{
		while (low != a->top)
			ra(a);
		pb(a,b);
		return ;
	}
	while (low != a->top)
		rra(a);
	pb(a,b);
	return ;
}
