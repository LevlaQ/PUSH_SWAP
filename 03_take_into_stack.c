/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_take_into_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:12:05 by gyildiz           #+#    #+#             */
/*   Updated: 2025/03/01 12:57:14 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Takes command-line arguments and stores them in stack A.
 * Handles both cases:
 * 1. Multiple arguments: "./a.out 3 5 1"
 * 2. Single string argument: "./a.out '3 5 1'"
 *
 * - Uses `ft_split` to separate numbers if given as a single string.
 * - Calls `into_stack()` to push numbers onto stack A.
 * - Calls `index_the_stack()` to assign indices to each node.
 * - Frees memory allocated for `ft_split` results.
 *
 * Returns 1 on success, 0 on failure.
 */
int	to_the_stack_a_main(int argc, char **argv, t_p **lst)
{
	char	**a_values;
	int		stcnt;

	if (argc == 2)
	{
		a_values = ft_split(argv[1], ' ');
		if (!a_values)
			return (write(2, "Error\n", 6), 0);
		stcnt = 0;
		while (a_values[stcnt])
			stcnt++;
		if (!into_stack(stcnt, a_values, lst))
			return (write(2, "Error\n", 6), 0);
		index_the_stack(lst);
		free_strings(a_values);
	}
	else if (argc > 2)
	{
		if (!into_stack(argc - 1, argv + 1, lst))
			return (write(2, "Error\n", 6), 0);
		index_the_stack(lst);
	}
	return (1);
}

/*
 * Pushes numbers from an array into the stack.
 * - Converts each string number into an integer.
 *
	- Calls `add_plate_front()` to insert each number at the beginning of the stack.
 *
 * Returns 1 on success, 0 on failure.
 */
int	into_stack(int argc, char **el, t_p **lst)
{
	int	i;
	int	value;

	i = argc - 1;
	while (i >= 0)
	{
		value = ft_atoi(el[i]);
		if (!add_plate_front(lst, value))
			return (0);
		i--;
	}
	return (1);
}

/*
 * Creates a new node (plate) and adds it to the front of the stack.
 * - Allocates memory for a new `t_p` node.
 * - Assigns the given `number` to the node.
 * - Updates `next` and `prev` pointers to maintain the doubly linked list.
 *
 * Returns 1 on success, 0 if memory allocation fails.
 */
int	add_plate_front(t_p **lst, int number)
{
	t_p	*new_plate;

	new_plate = (t_p *)ft_calloc(1, sizeof(t_p));
	if (!new_plate)
		return (0);
	new_plate->value = number;
	new_plate->next = *lst;
	new_plate->prev = NULL;
	if (*lst)
		(*lst)->prev = new_plate;
	*lst = new_plate;
	return (1);
}

/*
 * Assigns an index to each node in the stack.
 * - Indexing helps with operations like sorting and finding positions.
 */
void	index_the_stack(t_p **lst)
{
	t_p		*iter;
	int		i;

	i = 0;
	iter = *lst;
	while (iter)
	{
		iter->index = i;
		iter = iter->next;
		i++;
	}
}
