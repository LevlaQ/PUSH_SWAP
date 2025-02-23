/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:12:18 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/09 19:13:02 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_strings(char **strings)
{
	size_t	i;

	if (!strings)
		return;
	i = 0;
	while (strings[i]) // Alt stringleri serbest bırak
	{
		free(strings[i]);
		i++;
	}
	free(strings); // Son olarak ana pointer'ı serbest bırak
}