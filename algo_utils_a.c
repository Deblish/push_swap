/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:03:42 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/05 14:15:54 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//------------------erase
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
	//printf("\t\t\t");
	//return (NULL);
	return (stack->top);
	//return (stack->min);
}

t_node	*find_cheapest_a_to_b(t_stack *a, t_stack *b)
{
	size_t	best;
	t_node	*cheapest;
	t_node	*node;
	t_instr	a_instr;
	t_instr	b_instr;

	best = INT_MAX;
	cheapest = NULL;
	node = a->top;
	while(node)
	{
		//printf("node %i on top of %p ; ", node->value, get_target_a_to_b(b, node));
		get_pop_info(a, node, &a_instr, 'a');
		get_pop_info(b, get_target_a_to_b(b, node), &b_instr, 'b');
		//printf("rot_cost_a: %i ; ", (int)a_instr.cost);
		//printf("rot_cost_b: %i\n", (int)b_instr.cost);
		if (!cheapest || a_instr.cost + b_instr.cost + (node != a->top) < best)
		{
			cheapest = node;
			best = a_instr.cost + b_instr.cost;
		}
		node = node->next;
	}
	//printf("\ttotal: %i", (int)best);
	return (cheapest);
}

void	do_cheapest_a_to_b(t_stack *a, t_stack *b)
{
	t_node	*cheapest;
	t_instr	a_instr;
	t_instr	b_instr;

	cheapest = find_cheapest_a_to_b(a, b);
	if (!cheapest) //stack a is empty
		return ;
	//printf("\tbest_node: %i\n", cheapest->value);
	//print_stack(a->top, 1);
	//print_stack(b->top, 2);
	get_pop_info(a, cheapest, &a_instr, 'a');
	get_pop_info(b, get_target_a_to_b(b, cheapest), &b_instr, 'b');
	if (ft_strlen(a_instr.operation) == ft_strlen(b_instr.operation))
	{
		if (!ft_strncmp(a_instr.operation, "ra", 2))
			while(a_instr.cost && b_instr.cost && a_instr.cost-- && b_instr.cost--)
				rr(a, b);
		else if (!ft_strncmp(a_instr.operation, "rra", 2))
			while(a_instr.cost && b_instr.cost && a_instr.cost-- && b_instr.cost--)
				rrr(a, b);
	}
	do_op(a, b, a_instr.cost, a_instr.operation);
	do_op(a, b, b_instr.cost, b_instr.operation);
	do_op(a, b, 1, "pb");
	//printf("\n");
	//print_stack(a->top, 1);
	//print_stack(b->top, 2);
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
