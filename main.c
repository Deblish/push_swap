/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:06:44 by aapadill          #+#    #+#             */
/*   Updated: 2024/07/19 16:15:44 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!fill_stack(new_stack, argc, argv))
		return (NULL);
	return (new_stack);
}

static void	print_stack(t_node	*i, int option)
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
	//error -> argv[n] is duplicate
	n = argc;
	while (n--)
	{
		if (!argv[n] || ft_atoi_overflow(argv[n]) || has_duplicates(n, argv))
		{
			//ft_printf("%s\n", argv[n]);
			ft_printf("error\n");
			return (1);
		}
	}
	a = init_stack(argc, argv); //if a = NULL, error
	b = init_stack(0, argv); //if b = NULL, error, but you gotta free a?
	selection_sort(a, b);
	print_stack(a->top, 1);
	return 0;
}
