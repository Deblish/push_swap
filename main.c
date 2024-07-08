/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:06:44 by aapadill          #+#    #+#             */
/*   Updated: 2024/07/08 15:15:16 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*init_node(int value)
{
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

	while (argc && argv)
	{
		new_node = init_node(ft_atoi(argv[argc]));
		if (!new_node)
		{
			while (stack->size)
				free(pop(stack));
			free(stack);
			return (0);
		}
		push(stack, new_node);
		argc++;
	}
	return (1);
}

static void	init_stack(t_stack **stack, int argc, char **argv)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
	{
		*stack = NULL;
		return ;
	}
	new_stack->top = NULL;
	new_stack->size = 0;
	*stack = new_stack;
	if (!fill_stack(new_stack, argc, argv))
		*stack = NULL;
}

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
	//error -> argv[n] > int, argv[n] is duplicate
	while (*argv && ft_isdigit_str(*argv))
		ft_printf("%s\n", *argv++);
	return 1;
	init_stack(&a, argc, argv); //if a = NULL, error
	init_stack(&b, 1, argv); //if b = NULL, error, but you gotta free a?
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
