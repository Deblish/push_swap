/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:06:44 by aapadill          #+#    #+#             */
/*   Updated: 2024/06/12 16:07:54 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

//static	init_stack()

/*
** @description
** Display the smallest list of instructions possible to  sort the stack a, 
** the smallest number being at the top.
** Sort the stack with the lowest possible number of operations.
** Instructions must be separated by a ’\n’ and nothing else.
**
** @param
** Takes the stack as an argument, formatted as a list of integers. 
** The first argument should be at the top of the stack.
**
** @return
** If no parameters are specified, the program must not display anything and
** give the prompt back.
** In case of error, it must display "Error" followed by a ’\n’ on the 
** standard input.
** Errors include for example: some arguments aren’t integers, some arguments 
** are bigger than an integer and/or there are duplicates
*/

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	//error -> arguments not integers, > int, duplicates
	int i = 0;
	while(++i < argc)
		printf("argv[%i] ->%s\n", i, argv[i]);
	return 0;
}
