/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:16:54 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/04 14:52:14 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sa(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}
