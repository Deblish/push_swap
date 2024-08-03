/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:50:42 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/03 14:00:41 by aapadill         ###   ########.fr       */
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

size_t	get_pop_cost(t_stack *stack, t_node *stop)
{
	size_t	forward;
	size_t	backward;
	t_node	*current;

	forward = 0;
	current = stack->top;
	while (current && current != stop)
	{
		forward++;
		current = current->next;
	}
	if (!current)
		return (0);
	backward = stack->size - forward;
	if (forward < backward)
		return (forward);
	else
		return (backward);
}

char	*get_pop_op(t_stack *stack, t_node *stop, char op)
{
	size_t	forward;
	size_t	backward;
	t_node	*current;

	forward = 0;
	current = stack->top;
	while (current && current != stop)
	{
		forward++;
		current = current->next;
	}
	if (!current)
		return (NULL);
	backward = stack->size - forward;
	if (forward < backward)
	{
		if (op == 'a')
			return ("ra");
		return ("rb");
	}
	else
	{
		if (op == 'a')
			return ("rra");
		return ("rrb");
	}
}

t_node	*get_node(t_stack *stack, t_node *node)
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
				return (current->next); //return (current); 
		current = current->next;
	}
	if (node->value < stack->top->value && node->value > current->value)
		return (current);
	//printf("\t\t\t");
	//return (NULL);
	return (stack->top);
	//return (stack->min);
}


void	do_op(t_stack *a, t_stack *b, size_t cost, char *op)
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

void	do_cheapest_to_b(t_stack *a, t_stack *b)
{
	size_t	total;
	size_t	best;
	t_node	*cheapest;
	t_node	*node;
	t_node	*on_top_of_what;
	size_t	moves;
	char	*op;

	cheapest = NULL;
	best = INT_MAX;
	node = a->top;
	while(node)
	{
		on_top_of_what = get_node(b, node);
		printf("node %i on top of %p ; ", node->value, on_top_of_what);
		total = get_pop_cost(a, node) + get_pop_cost(b, on_top_of_what);
		printf("rot_cost_a: %i ; ", (int)get_pop_cost(a, node));
		printf("rot_cost_b: %i\n", (int)get_pop_cost(b, on_top_of_what));
		if (!cheapest || total < best)
		{
			cheapest = node;
			best = total;
		}
		node = node->next;
	}
	if (!cheapest)
		return ;
	printf("\tbest_node: %i ; total: %i\n", cheapest->value, (int)best);
	print_stack(a->top, 1);
	print_stack(b->top, 2);

	moves = get_pop_cost(b, get_node(b, cheapest));
	op = get_pop_op(b, get_node(b, cheapest), 'b');
	do_op(a, b, get_pop_cost(a, cheapest), get_pop_op(a, cheapest, 'a'));
	do_op(a, b, moves, op);
	do_op(a, b, 1, "pb");

	printf("\n");
	print_stack(a->top, 1);
	print_stack(b->top, 2);
}
