/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:59:42 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/01 02:53:17 by aapadill         ###   ########.fr       */
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
	//ft_printf("\tstack->size = %i\n", (int)stack->size);
	//ft_printf("\tstack->max = %i\n", (int)stack->max->value);
	//ft_printf("\tstack->min = %i\n", (int)stack->min->value);
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
	//if (stack->max)
	//	ft_printf("\tstack_a->max = %i\n", (int)stack->max->value);
	//if (stack->min)
	//	ft_printf("\tstack_a->min = %i\n", (int)stack->min->value);
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
	top = stack->top;
	below = top->next;
	top->next = below->next;
	below->next = top;
	stack->top = below;
	//update_min_and_max(stack, top);
	//update_min_and_max(stack, below);
}

/*
** @update
** Directly manipulating the data, using pop created an invisible bug for the
** stack->min and stack->max value
**
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
	ex_top = stack->top;
	bottom = stack->top->next;
	stack->top = bottom;
	while(bottom->next)
		bottom = bottom->next;
	bottom->next = ex_top;
	ex_top->next = NULL;
}

/*
** @update
** Same as rotate, push() call is not used anymore, since it created a really
** invisible bug where some values at stack->min and stack->max weren't correct
**
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
	bottom->next = stack->top;
	stack->top = bottom;
}
