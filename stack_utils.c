/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:59:42 by aapadill          #+#    #+#             */
/*   Updated: 2024/07/11 18:00:10 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!stack->top || !stack->size)
	{
		stack->top = node;
		stack->size += 1;
		return ;
	}
	node->next = stack->top;
	stack->top = node;
	stack->size += 1;
}

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

	if (!stack->top || !stack->size)
		return (NULL);
	popped = stack->top;
	stack->top = popped->next;
	stack->size -= 1;
	popped->next = NULL;
	return (popped);
}

/*
** @description
** Swap the first two nodes at the top of stack
** Do nothing if there is only one or no nodes
**
** @param
** Pointer to stack
**
** @return
*/
void	swap(t_stack *stack)
{
	t_node *top;
	t_node *below;

	if (stack->size < 2)
		return ;
	top = pop(stack);
	below = pop(stack);
	push(stack, top);
	push(stack, below);
}

/*
** @note
** Refactoring might be needed: create push_bottom(*stack, *node)
**
** @description
** Shift up one node in the stack (top node goes to the bottom of the stack)
** Do nothing if there is only one or no nodes
**
** @param
** Pointer to stack
**
** @return
*/
void	rotate(t_stack *stack)
{
	t_node	*ex_top;
	t_node	*bottom;

	if (stack->size < 2)
		return ;
	ex_top = pop(stack);
	bottom = stack->top;
	while(bottom->next)
		bottom = bottom->next;
	bottom->next = ex_top;
	stack->size += 1;
}

/*
** @note
** Refactoring might be needed: create pop_bottom(*stack);
**
** @description
** Shift down one node in the stack (bottom node goes to the top of the stack)
** Do nothing if there is only one or no nodes
**
** @param
** Pointer to stack
**
** @return
*/
void	reverse_rotate(t_stack *stack)
{
	t_node	*bottom;
	t_node	*before_bottom;

	if (stack->size < 2)
		return ;
	before_bottom = stack->top;
	bottom = before_bottom->next;
	while(bottom->next)
	{
		before_bottom = bottom;
		bottom = bottom->next;
	}
	before_bottom->next = NULL;
	stack->size -= 1;
	push(stack, bottom);
}
