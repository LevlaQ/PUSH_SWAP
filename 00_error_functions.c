/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_error_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:49:04 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/27 16:05:17 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
 * Main error handling function.
 * - Checks if the argument count is valid.
 * - Calls appropriate error functions based on input type.
 */
int	error_main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(2, "Error(No input provided)\n", 26);
		return (0);
	}
	if (argc == 2)
	{
		if(!error_two_args(argv))
			return (0);
	}
	if (argc > 2)
	{
		if(!error_multi_args(argv))
			return (0);
	}
	return (1);
}

/* 
 * Checks if a single argument (string format) is valid.
 * - Splits the string into separate numbers.
 * - Validates character rules, number limits, and duplicates.
 */
int error_two_args(char **argv)
{
	char **el;

	if (!chk_if_string(argv[1]))
		return (write(2, "Error(There is only one integer)\n", 34), 0);
	if (argv[1][0] == '\0' || !argv[1])
		return (write(2, "Error(No input provided)\n", 26), 0);
	if (!chk_spaces(argv[1]))
		return (write(2, "Error(There are multiple spaces)\n", 34), 0);
	el = ft_split(argv[1], ' ');
	if (!el || !el[0])
		return ( write(2, "Error(ft_split failed)\n", 24), 0);
	if (!chk_chrctrs(el))
		return (write(2, "Error(Forbidden chars!)\n", 25), free_strings(el), 0);
	if (!chk_integers_general(el))
		return (free_strings(el), 0);
	return (free_strings(el), 1);
}

/* 
 * Checks if multiple arguments (space-separated) are valid.
 * - Ensures that all arguments follow integer format.
 * - Prevents mixed syntax usage.
 */
int error_multi_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (chk_if_string(argv[i]))
		{
			write(2, "Error(Can't use mixed syntax)\n", 31);
			return (0);
		}
		i++;
	}
	argv = argv + 1;
	if (!chk_chrctrs(argv))
	{
		write(2, "Error(There are forbidden chars)\n", 34);
		return (0);
	}
	if (!chk_integers_general(argv))
	{
		return (0);
	}
	return (1);
}

/* 
 * Checks if an argument is a string (multiple numbers in a single argument).
 * - Uses ft_split() to split the input.
 * - If splitting results in multiple elements, it's a string.
 */
int	chk_if_string(char *str)
{
	char	**el;
	int		i;
	
	el = ft_split(str, ' ');
	if (!el)
		return (0);
	i = 0;
	while (el[i])
		i++;
	if(i == 1)
	{
		free_strings(el);
		return (0);
	}
	free_strings(el);
	return (1);
}

/* 
 * Checks for multiple consecutive spaces in an argument.
 * - Returns 0 if two or more spaces appear in a row.
 */
int	chk_spaces(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
	{
		if ((str[i] == ' ') && (str[i + 1] == ' '))
			return (0);
		i++;
	}
	return (1);
}