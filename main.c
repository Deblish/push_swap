/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:06:44 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/05 14:16:23 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //--------------------------------erase

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	old_argc;
	int	n;
	int	gotta_free;

	gotta_free = 0;
	if (argc < 2)
		return (0);
	old_argc = argc;
	if (argc == 2 && ++gotta_free)
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
			if (gotta_free)
			{
				while(argc--)
					free(argv[argc]);
				free(argv);
			}
			return (1);
		}
	}
	a = init_stack(argc, argv); //if a = NULL, error
	b = init_stack(0, argv); //if b = NULL, error, but you gotta free a?
	algo(a, b);
	//selection_sort(a, b);
	//print_stack(a->top, 1);
	//print_stack(b->top, 2);
	while(a->size)
		free(pop(a));
	free(a);
	free(b);
	if (gotta_free)
	{
		while(argc--)
			free(argv[argc]);
		free(argv);
	}
	return 0;
}
