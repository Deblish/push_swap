/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:50:42 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/06 12:14:28 by aapadill         ###   ########.fr       */
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
		instr->op = NULL;
		return ;
	}
	backward = stack->size - forward;
	if (forward < backward)
	{
		instr->cost = forward;
		if (s == 'a')
			instr->op = "ra";
		else if (s == 'b')
			instr->op = "rb";
	}
	else
	{
		instr->cost = backward;
		if (s == 'a')
			instr->op = "rra";
		else if (s == 'b')
			instr->op = "rrb";
	}
}

int	op_reducer(t_instr *a, t_instr *b)
{
	int	rr;
	int	rrr;

	rr = 0;
	rrr = 0;
	if (!ft_strncmp(a->op, "ra", 2) && !ft_strncmp(b->op, "rb", 2))
	{
		while(a->cost && b->cost && a->cost-- && b->cost--)
			rr++;
		return (rr);
	}
	if (!ft_strncmp(a->op, "rra", 3) && !ft_strncmp(b->op, "rrb", 3))
	{
		while(a->cost && b->cost && a->cost-- && b->cost--)
			rrr++;
		return (rrr);
	}
	return (0);
}

void	do_op(t_stack *a, t_stack *b, size_t cost, const char *op)
{
	if (!ft_strncmp(op, "pa", 2))
		while (cost--)
			pa(a,b);
	else if(!ft_strncmp(op, "pb", 2))
		while (cost--)
			pb(a,b);
	else if (!ft_strncmp(op, "ra", 2))
		while (cost--)
			ra(a);
	else if (!ft_strncmp(op, "rb", 2))
		while (cost--)
			rb(b);
	else if (!ft_strncmp(op, "rra", 3))
		while (cost--)
			rra(a);
	else if (!ft_strncmp(op, "rrb", 3))
		while (cost--)
			rrb(b);
	else if (!ft_strncmp(op, "rrr", 3))
		while (cost--)
			rrr(a, b);
	else if (!ft_strncmp(op, "rr", 2))
		while (cost--)
			rr(a, b);
	return ;
}
