/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:50:42 by aapadill          #+#    #+#             */
/*   Updated: 2024/07/27 04:14:11 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_min_and_max(t_stack *stack, t_node *new_node)
{
	if (!stack->max || new_node->value > stack->max->value)
		stack->max = new_node;
	if (!stack->min || new_node->value < stack->min->value)
		stack->min = new_node;
}

size_t	get_pop_cost(t_stack *stack, t_node *stop)
{
	size_t	forward;
	size_t	backward;
	t_node	*current;

	forward = 1;
	current = stack->top;
	while (current && current != stop)
	{
		forward++;
		current = current->next;
	}
	if (!current)
		return (0);
	backward = stack->size - forward + 2;
	if (forward < backward)
		return (forward);
	else
		return (backward);
}

size_t	get_push_cost_b(t_stack *stack, t_node *node)
{
	size_t	reverse;
	size_t	rotate;
	t_node	*current;

	reverse = 0;
	current = stack->top;
	if (!current)
		return (0);
	if (is_ordered(stack, 1) && node->value < stack->min->value)
	{
		ft_printf("rotate;");
		return (1); //rotate
	}
	while (current->next && current->value > node->value)
	{
		reverse++;
		current = current->next;
	}
	if (!current->next && current->value > node->value)
		reverse++;
	rotate = stack->size - reverse + 1;
	if (reverse < rotate)
	{
		if (reverse == 1)
			ft_printf("swap;");
		else
			ft_printf("revers;");
		return (reverse); //if 1, equivalent to swap
	}
	ft_printf("rotate;");
	return (rotate);
}

/*
void	algorithm(t_stack *a, t_stack b)
{
	t_node	*current;
	while(current)
	{
		size_t	pop_cost;
		size_t	push_cost;
		size_t	total;
		size_t	best;
		t_node	*best_candidate;

		best_candidate = NULL;
		best = INT_MAX;
		pop_cost = get_pop_cost(a, current);
		push_cost = get_push_cost_b(b, current);
		total = pop_cost + push_cost;
		if (!candidate || total < best)
		{
			best_candidate = current;
			best = total;
		}
		current = current->next;
	}
}
*/

int	is_ordered(t_stack *stack, int from_max)
{
	t_node	*first;
	t_node	*second;

	first = stack->top;
	second = first->next;
	while (second)
	{
		if (!from_max && first->value > second->value)
			break;
		if (from_max && first->value < second->value)
			break;
		first = second;
		second = second->next;
	}
	if (!second)
		return (1);
	return (0);
}
