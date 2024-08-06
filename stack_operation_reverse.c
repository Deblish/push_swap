/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_reverse.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:20:26 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/06 15:50:58 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (bottom->next)
	{
		before_bottom = bottom;
		bottom = bottom->next;
	}
	before_bottom->next = NULL;
	bottom->next = stack->top;
	stack->top = bottom;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
