/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 07:31:45 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/03 19:01:07 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../ft_printf/include/ft_printf.h"
# include "../libft/libft.h"

typedef struct	s_node
{
	int			value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	size_t	size;
	t_node	*max;
	t_node	*min;
}	t_stack;

typedef struct	s_instruction
{
	int	cost;
	const char	*operation;
}	t_instr;

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

void	print_stack(t_node	*i, int option);

void	update_min_and_max(t_stack *stack, t_node *new_node);
int		is_ordered(t_stack *stack, int from_max);
void	get_pop_info(t_stack *stack, t_node *stop, t_instr *instr, char s);
t_node	*get_node(t_stack *stack, t_node *node);
void	do_op(t_stack *a, t_stack *b, size_t cost, const char *op);
void	do_cheapest_to_b(t_stack *a, t_stack *b);

void	low_extractor(t_stack *a, t_stack *b);
void	selection_sort(t_stack *a, t_stack *b);
#endif
