/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 08:01:55 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/05 10:45:21 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //------------------------erase
#include "push_swap.h"

t_node	*get_target_b_to_a(t_stack *stack, t_node *node)
{
	t_node	*current;

	current = stack->top;
	if (!stack->size)
		return (NULL);
	if (stack->size == 1)
		return (current);
	if (node->value > stack->max->value)
		return (stack->min);
	if (node->value < stack->min->value)
		return (stack->min);
	while (current->next)
	{
		if (node->value > current->value)
			if (node->value < current->next->value)
				return (current->next);
		current = current->next;
	}
	if (node->value > stack->top->value)
		if (node->value < current->value)
			return (current);
	//printf("\t\t\t");
	//return (NULL);
	return (stack->top);
	//return (stack->min);
}

void	do_move_b_to_a(t_stack *a, t_stack *b)
{
	t_node	*target;
	t_instr	a_instr;
	t_instr	b_instr;

	get_pop_info(b, b->max, &b_instr, 'b');
	target = get_target_b_to_a(a, b->max);
	if (!target) //stack a is empty
		return ;
	get_pop_info(a, target, &a_instr, 'a');
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
	do_op(a, b, 1, "pa");
}

void	algo(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	while (a->size > 3)
		do_cheapest_a_to_b(a, b);
	sort_three_a(a);
	while(b->size)
		do_move_b_to_a(a, b);
}
