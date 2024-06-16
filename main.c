/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:06:44 by aapadill          #+#    #+#             */
/*   Updated: 2024/06/16 14:09:27 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*init_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	//if (!new_node) return ;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

static void	init_stack(t_stack **stack, int argc, char **argv)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	//if (!new_stack) return ;
	new_stack->top = NULL;
	new_stack->size = 0;
	*stack = new_stack;
	//change argc
	while (--argc)
		push(new_stack, init_node(atoi(argv[argc])));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	if (argc < 2)
		return (0);
	//error -> if arg[n] not integer, argv[n] > int, argv[n] is duplicate
	init_stack(&a, argc, argv);
	init_stack(&b, 1, argv);
	//testing with example in subject
	sa(a);
	pb(a,b);
	pb(a,b);
	pb(a,b);
	ra(a);
	rb(b);
	rra(a);
	rrb(b);
	sa(a);
	pa(a,b);
	pa(a,b);
	pa(a,b);
	//printing stacks
	t_node	*i = a->top;
	while (i)
	{
		ft_printf("%i\n", i->value);
		i = i->next;
	}
	i = b->top;
	while (i)
	{
		ft_printf("\t%i\n", i->value);
		i = i->next;
	}
	return 0;
}
