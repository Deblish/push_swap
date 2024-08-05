/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:50:42 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/04 14:42:57 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//------------------erase
#include "push_swap.h"

void	update_min_and_max(t_stack *stack, t_node *new_node)
{
	if (!stack->max || new_node->value > stack->max->value)
		stack->max = new_node;
	if (!stack->min || new_node->value < stack->min->value)
		stack->min = new_node;
}

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

void	get_pop_info(t_stack *stack, t_node *stop, t_instr *instr, char s)
{
	size_t	forward;
	size_t	backward;
	t_node	*current;

	forward = 0;
	current = stack->top;
	if (!instr)
		return ;
	while (current && current != stop)
	{
		forward++;
		current = current->next;
	}
	if (!current)
	{
		instr->cost = 0;
		instr->operation = NULL;
		return ;
	}
	backward = stack->size - forward;
	if (forward < backward)
	{
		instr->cost = forward;
		if (s == 'a')
			instr->operation = "ra";
		else if (s == 'b')
			instr->operation = "rb";
	}
	else
	{
		instr->cost = backward;
		if (s == 'a')
			instr->operation = "rra";
		else if (s == 'b')
			instr->operation = "rrb";
	}
}

void	do_op(t_stack *a, t_stack *b, size_t cost, const char *op)
{
	if (!op)
		return ;
	if (!ft_strncmp(op, "pa", 2))
		while (cost--)
			pa(a,b);
	if (!ft_strncmp(op, "pb", 2))
		while (cost--)
			pb(a,b);
	if (!ft_strncmp(op, "ra", 2))
		while (cost--)
			ra(a);
	if (!ft_strncmp(op, "rb", 2))
		while (cost--)
			rb(b);
	if (!ft_strncmp(op, "sb", 2))
		while (cost--)
			sb(b);
	if (!ft_strncmp(op, "rrb", 3))
		while (cost--)
			rrb(b);
	if (!ft_strncmp(op, "rra", 3))
		while (cost--)
			rra(a);
}
