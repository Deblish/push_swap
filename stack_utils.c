/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:59:42 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/06 14:57:53 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

int	fill_stack(t_stack *stack, int argc, char **argv)
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

t_stack	*init_stack(int argc, char **argv)
{
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
