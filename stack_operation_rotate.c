/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:19:01 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/04 14:52:55 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ra(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
