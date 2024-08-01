/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:17:45 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/01 02:53:40 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = pop(b);
	if (node)
		push(a, node);
	//else
	//	ft_printf("b is empty\n");
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = pop(a);
	if (node)
		push(b, node);
	//else
	//	ft_printf("a is empty\n");
	ft_printf("pb\n");
}
