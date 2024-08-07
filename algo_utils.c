/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:50:42 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/07 16:40:57 by aapadill         ###   ########.fr       */
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
			break ;
		if (from_max && first->value < second->value)
			break ;
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
	t_node	*current;

	forward = 0;
	current = stack->top;
	while (current && current != stop)
	{
		forward++;
		current = current->next;
	}
	if (forward < (stack->size - forward))
	{
		instr->cost = forward;
		if (s == 'a')
			instr->op = "ra";
		else if (s == 'b')
			instr->op = "rb";
		return ;
	}
	instr->cost = stack->size - forward;
	if (s == 'a')
		instr->op = "rra";
	else if (s == 'b')
		instr->op = "rrb";
}

int	op_reducer(t_instr *a, t_instr *b, int save)
{
	int	count;

	count = 0;
	if ((!ft_strncmp(a->op, "ra", 2) && !ft_strncmp(b->op, "rb", 2))
		|| (!ft_strncmp(a->op, "rra", 3) && !ft_strncmp(b->op, "rrb", 3)))
	{
		while (a->cost && b->cost && a->cost-- && b->cost--)
			count++;
		if (!save)
		{
			a->cost += count;
			b->cost += count;
		}
		return (count);
	}
	return (0);
}

void	do_op(t_stack *a, t_stack *b, size_t cost, const char *op)
{
	if (!ft_strncmp(op, "pa", 2))
		while (cost--)
			pa(a, b);
	else if (!ft_strncmp(op, "pb", 2))
		while (cost--)
			pb(a, b);
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
}
