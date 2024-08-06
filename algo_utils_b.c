/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 08:01:55 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/06 12:16:36 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (stack->top);
}

void	do_move_b_to_a(t_stack *a, t_stack *b)
{
	t_node	*target;
	t_instr	a_instr;
	t_instr	b_instr;

	get_pop_info(b, b->max, &b_instr, 'b');
	target = get_target_b_to_a(a, b->max);
	if (!target)
		return ;
	get_pop_info(a, target, &a_instr, 'a');
	if (!ft_strncmp(a_instr.op, "ra", 2))
		do_op(a, b, op_reducer(&a_instr, &b_instr), "rr");
	else if (!ft_strncmp(a_instr.op, "rra", 3))
		do_op(a, b, op_reducer(&a_instr, &b_instr), "rrr");
	do_op(a, b, a_instr.cost, a_instr.op);
	do_op(a, b, b_instr.cost, b_instr.op);
	do_op(a, b, 1, "pa");
}
