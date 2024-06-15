/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 07:31:45 by aapadill          #+#    #+#             */
/*   Updated: 2024/06/15 19:56:03 by aapadill         ###   ########.fr       */
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
}	t_stack;

t_node	*pop(t_stack *stack);
void push(t_stack *stack, t_node *new_node);
void	swap(t_stack *stack);

#endif
