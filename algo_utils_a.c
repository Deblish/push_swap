/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:03:42 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/06 12:21:49 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_target_a_to_b(t_stack *stack, t_node *node)
{
	t_node	*current;

	current = stack->top;
	if (!stack->size)
		return (NULL);
	if (stack->size == 1)
		return (current);
	if (node->value > stack->max->value)
		return (stack->max);
	if (node->value < stack->min->value)
		return (stack->max);
	while (current->next)
	{
		if (node->value < current->value)
			if (node->value > current->next->value)
				return (current->next);
		current = current->next;
	}
	if (node->value < stack->top->value && node->value > current->value)
		return (current);
	return (stack->top);
}

t_node	*find_cheapest_a_to_b(t_stack *a, t_stack *b)
{
	size_t	best;
	size_t	total;
	t_node	*cheapest;
	t_node	*node;
	t_instr	a_instr;
	t_instr	b_instr;

	best = INT_MAX;
	cheapest = NULL;
	node = a->top;
	while(node)
	{
		get_pop_info(a, node, &a_instr, 'a');
		get_pop_info(b, get_target_a_to_b(b, node), &b_instr, 'b');
		//if (a_instr.cost + b_instr.cost + (node != a->top) < best)
		total = op_reducer(&a_instr, &b_instr) + a_instr.cost + b_instr.cost; 
		if (total < best)
		{
			cheapest = node;
			//best = a_instr.cost + b_instr.cost;
			best = total;
		}
		node = node->next;
	}
	return (cheapest);
}

void	do_cheapest_a_to_b(t_stack *a, t_stack *b)
{
	t_node	*cheapest;
	t_instr	a_instr;
	t_instr	b_instr;

	cheapest = find_cheapest_a_to_b(a, b);
	if (!cheapest)
		return ;
	get_pop_info(a, cheapest, &a_instr, 'a');
	get_pop_info(b, get_target_a_to_b(b, cheapest), &b_instr, 'b');
	if (!ft_strncmp(a_instr.op, "ra", 2))
		do_op(a, b, op_reducer(&a_instr, &b_instr), "rr");
	else if (!ft_strncmp(a_instr.op, "rra", 3))
		do_op(a, b, op_reducer(&a_instr, &b_instr), "rrr");
	do_op(a, b, a_instr.cost, a_instr.op);
	do_op(a, b, b_instr.cost, b_instr.op);
	do_op(a, b, 1, "pb");
}

void	sort_three_a(t_stack *a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (a->size > 3 || is_ordered(a, 0))
		return ;
	while (!is_ordered(a, 0))
	{
		first = a->top;
		second = first->next;
		third = second->next;
		if (first && second && first->value > second->value)
			sa(a);
		if (second && third && second->value > third->value)
			rra(a);
	}
	return ;
}
