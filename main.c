/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:06:44 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/05 10:48:35 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //--------------------------------erase

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
	algo(a, b);
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
