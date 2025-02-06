/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:49:08 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/05 15:38:01 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*iter;

	if (!lst || !del)
		return ;
	iter = *lst;
	while (iter != NULL)
	{
		temp = iter->next;
		del(iter->content);
		free(iter);
		iter = temp;
	}
	*lst = NULL;
}
