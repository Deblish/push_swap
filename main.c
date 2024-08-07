/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:06:44 by aapadill          #+#    #+#             */
/*   Updated: 2024/08/07 15:12:10 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_argv(int fake_argv, int argc, char **argv, int send_error)
{
	if (fake_argv)
	{
		while (argc--)
			free(argv[argc]);
		free(argv);
	}
	if (send_error)
		write(2, "Error\n", 6);
	return (0);
}

int	init_both_stacks(t_stack **a, t_stack **b, int argc, char **argv)
{
	*a = init_stack(argc, argv);
	if (!*a)
		return (0);
	*b = init_stack(0, argv);
	if (!*b)
		return (free_stack(*a, 1));
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		old_argc;
	int		n;
	int		fake_argv;

	fake_argv = 0;
	if (argc < 2)
		return (0);
	old_argc = argc;
	if (argc == 2 && ++fake_argv)
		argv = ft_split(argv[1], ' ', &argc);
	else if (argc == old_argc && argv++)
		argc--;
	n = argc;
	while (n--)
		if (!argv[n] || int_overflows(argv[n]) || has_duplicates(n, argv))
			return (free_argv(fake_argv, argc, argv, 1));
	if (!init_both_stacks(&a, &b, argc, argv))
		return (free_argv(fake_argv, argc, argv, 1));
	algo(a, b);
	free_stack(a, 0);
	free_stack(b, 0);
	return (free_argv(fake_argv, argc, argv, 0));
}
