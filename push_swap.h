/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 07:31:45 by aapadill          #+#    #+#             */
/*   Updated: 2024/07/26 20:19:33 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/include/ft_printf.h"
# include "../libft/libft.h"

typedef struct	s_node
{
	int			value; //maybe long
	struct s_node	*next;
	//struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	size_t	size;
	t_node	*max;
	t_node	*min;
}	t_stack;

void	push(t_stack *stack, t_node *new_node);
t_node	*pop(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	update_min_and_max(t_stack *stack, t_node *new_node);
size_t	get_pop_cost(t_stack *stack, t_node *stop);
size_t	get_push_cost_b(t_stack *stack, t_node *node);
int		is_ordered(t_stack *stack, int from_max);
void	low_extractor(t_stack *a, t_stack *b);
void	selection_sort(t_stack *a, t_stack *b);
#endif
