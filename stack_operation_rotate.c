/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:19:01 by aapadill          #+#    #+#             */
/*   Updated: 2024/06/16 14:19:50 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
