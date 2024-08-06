/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:17:45 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/06 16:26:41 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @description
** Pop the top node of the stack
** Do nothing if there is no node
**
** @param
** Pointer to stack
**
** @return
** Pointer to popped node or
** NULL if stack is empty
*/
t_node	*pop(t_stack *stack)
{
	t_node	*popped;
	t_node	*i;

	if (!stack->top || !stack->size)
		return (NULL);
	popped = stack->top;
	stack->top = popped->next;
	stack->size -= 1;
	popped->next = NULL;
	if (popped == stack->max || popped == stack->min)
	{
		stack->max = NULL;
		stack->min = NULL;
		i = stack->top;
		while (i)
		{
			update_min_and_max(stack, i);
			i = i->next;
		}
	}
	return (popped);
}

/*
** @description
** Push one node to the top of the stack
**
** @param
** Pointer to node
** Pointer to stack
**
** @return
*/
void	push(t_stack *stack, t_node *node)
{
	update_min_and_max(stack, node);
	if (!stack->top)
	{
		stack->top = node;
		stack->size++;
		return ;
	}
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = pop(b);
	if (node)
		push(a, node);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = pop(a);
	if (node)
		push(b, node);
	ft_printf("pb\n");
}
