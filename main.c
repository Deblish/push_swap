/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:06:44 by aapadill          #+#    #+#             */
/*   Updated: 2024/07/29 19:07:21 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //--------------------------------erase

static t_node	*init_node(int value)
{
	//ft_printf("init_node\n");
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

static int	fill_stack(t_stack *stack, int argc, char **argv)
{
	t_node	*new_node;

	while (argc)
	{
		new_node = init_node(ft_atoi(argv[--argc]));
		if (!new_node)
		{
			while (stack->size)
				free(pop(stack));
			free(stack);
			return (0);
		}
		push(stack, new_node);
	}
	return (1);
}

static t_stack	*init_stack(int argc, char **argv)
{
	//ft_printf("init_stack\n");
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->top = NULL;
	new_stack->size = 0;
	new_stack->max = NULL;
	new_stack->min = NULL;
	if (!fill_stack(new_stack, argc, argv))
		return (NULL);
	return (new_stack);
}

void	print_stack(t_node	*i, int option)
{
	while (i)
	{
		if (option == 1)
			ft_printf("%i\n", i->value);
		if (option == 2)
			ft_printf("\t%i\n", i->value);
		i = i->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	old_argc;
	int n;

	if (argc < 2)
		return (0);
	old_argc = argc;
	if (argc == 2)
		argv = ft_split(argv[1], ' ', &argc);
	else if (argc == old_argc)
	{
		argc--;
		argv++;
	}
	n = argc;
	while (n--)
	{
		if (!argv[n] || int_overflows(argv[n]) || has_duplicates(n, argv))
		{
			//ft_printf("%s\n", argv[n]);
			ft_printf("Error\n");
			return (1);
		}
	}
	a = init_stack(argc, argv); //if a = NULL, error
	b = init_stack(0, argv); //if b = NULL, error, but you gotta free a?
	/*
	pb(a, b);
	pb(a, b);
	pb(a, b);
	pb(a, b);
	rb(b);
	pb(a, b);
	rb(b);
	pb(a, b);
	rb(b);
	//pb(a, b);
	//sb(b);
	ft_printf("\tstack_a->max = %i\n", (int)a->max->value);
	ft_printf("\tstack_a->min = %i\n", (int)a->min->value);
	ft_printf("\tstack_b->max = %i\n", (int)b->max->value);
	ft_printf("\tstack_b->min = %i\n", (int)b->min->value);
	
	t_node *current = a->top;
	while (current )
	{
		int one = (int)get_pop_cost(a, current);
		int two = (int)get_push_cost_b(b, current);
		printf("\tpop_cost  %i = %i; ", current->value, one);
		printf(" push_cost to b = %i; sum = %i\n", two, one+two);
		current = current->next;
	}
	*/
	//while (a->size > 2)
	pb(a, b);
	pb(a, b);
	while (a->size > 2)
		do_cheapest_to_b(a, b);
	//ft_printf("is a ordered? %i\n", is_ordered(a, 0));
	//if (!b->max)
	//	ft_printf("\tstack_b->max = %p\n", b->max);
	//if (!b->min)
	//	ft_printf("\tstack_b->min = %p\n", b->min);
	//selection_sort(a, b);
	//print_stack(a->top, 1);
	//print_stack(b->top, 2);
	return 0;
}
