/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:54:07 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/28 11:46:17 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		node_count;
	t_list	*iter;

	node_count = 0;
	iter = lst;
	while (iter != NULL)
	{
		node_count++;
		iter = iter->next;
	}
	return (node_count);
}
