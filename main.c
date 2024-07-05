/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:06:44 by aapadill          #+#    #+#             */
/*   Updated: 2024/07/04 13:20:55 by aapadill         ###   ########.fr       */
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
	while (argc)
		push(new_stack, init_node(ft_atoi(argv[argc--])));
}

/*
static void	low_extractor(t_stack *a, t_stack *b)
{
	t_node	*i;
	t_node	*low;
	size_t moves;

	i = a->top;
	low = i;
	moves = 0;
	while(i->next)
	{
		i = i->next;
		moves++;
		if (i->value < low->value)
			low = i;
	}
	if (low == a->top)
	{
		pb(a,b);
		return ;
	}
	if (low == i)
	{
		rra(a);
		pb(a,b);
		return ;
	}
	if (a->size > 1 && low == a->top->next)
	{
		sa(a);
		pb(a,b);
		return ;
	}
	if (moves <= a->size / 2)
	{
		while (low != a->top)
			ra(a);
		pb(a,b);
		return ;
	}
	while (low != a->top)
		rra(a);
	pb(a,b);
	return ;
}
*/

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	old_argc;

	if (argc < 2)
		return (0);
	old_argc = argc;
	if (argc == 2)
		argv = ft_split(argv[1], ' ', &argc);
	else if (argc == old_argc)
		argv++;
	//error -> if argv[n] not integer, argv[n] > int, argv[n] is duplicate
	while (*argv && ft_isdigit_str(*argv))
		ft_printf("%s\n", *argv++);
	return 1;
	init_stack(&a, argc, argv);
	init_stack(&b, 1, argv);
	//while(a->size)
	//	low_extractor(a, b);
	/*
	while(b->size)
		pa(a,b);
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
	*/
	return 0;
}
