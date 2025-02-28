/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_error_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:49:23 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/28 12:20:46 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Checks if the input contains only valid characters.
 * - Allowed: digits (0-9) and '-' sign (only at the beginning of a number).
 * - Invalid cases: "32-", "--3", "003", etc.
 */
int	chk_chrctrs(char **el)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (el[i])
	{
		j = 0;
		while (el[i][j])
		{
			if ((el[i][j] != '-') && !ft_isdigit(el[i][j]) && (el[i][j] != '+'))
				return (0);
			else if ((el[i][0] == '-' && el[i][1] == '\0') || (el[i][0] == '+'
					&& el[i][1] == '\0'))
				return (0);
			else if ((j != 0 && el[i][j] == '-') || (j != 0 && el[i][j] == '+'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
 * General integer validation.
 * - Calls chk_minmax() to check if numbers are within int limits.
 * - Calls chk_if_repeats() to detect duplicate numbers.
 */
int	chk_integers_general(char **el)
{
	if (!chk_minmax(el))
	{
		write(2, "Error\n", 5);
		return (0);
	}
	if (!chk_if_repeats(el))
	{
		write(2, "Error\n", 5);
		return (0);
	}
	return (1);
}

/*
 * Checks if numbers are within integer limits.
 * - INT_MAX:  2147483647
 * - INT_MIN: -2147483648
 */
int	chk_minmax(char **el)
{
	int	i;

	i = 0;
	while (el[i])
	{
		if (!modified_atoi_limits(el[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
 * A custom atoi function with integer limit checking.
 * - Returns 0 if the number exceeds int range.
 * - Handles negative numbers correctly.
 */
int	modified_atoi_limits(char *str)
{
	int				i;
	int				sign;
	unsigned long	inte;

	i = 0;
	sign = 1;
	inte = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			sign = sign * -1;
	while (str[i] >= 48 && str[i] <= 57 && str[i])
	{
		inte = (inte * 10) + (str[i] - 48);
		i++;
		if (inte > 2147483647)
		{
			if (sign == 1)
				return (0);
			else if (inte > 2147483648)
				return (0);
		}
	}
	return (1);
}

/*
 * Checks if there are duplicate numbers in the input.
 * - Compares each number with every other number.
 * - Returns 0 if a duplicate is found.
 */
int	chk_if_repeats(char **el)
{
	int	i;
	int	j;

	i = 0;
	while (el[i])
	{
		j = 0;
		while (el[j])
		{
			if (i != j && ft_atoi(el[i]) == ft_atoi(el[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
