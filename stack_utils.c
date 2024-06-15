/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:59:42 by aapadill          #+#    #+#             */
/*   Updated: 2024/06/14 12:42:46 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @description
** Swap the first 2 elements at the top of stack x.
** Do nothing if there is only one or no elements.
**
** @param
** paramName Description of the parameter.
**
** @return

void	swap(t_stack *x)
{
	return ;
}


void	sa(t_stack *a)
{
	return ;
}


void	sb(t_stack *b)
{
	return ;
}

void	ss(t_stack *a, t_stack *b)
{
	return ;
}
*/

void push(t_stack **stack, t_node *new_node)
{
	t_stack	*aux_stack;

	aux_stack = *stack;
	if (!aux_stack->top || !aux_stack->size)
	{
		aux_stack->top = new_node;
		aux_stack->size += 1;
		return ;
	}
	new_node->next = aux_stack->top;
	aux_stack->top = new_node;
	aux_stack->size += 1;
}
