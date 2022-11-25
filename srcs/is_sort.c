/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:49:24 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/21 14:19:11 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sort(t_nblist *a)
{
	t_node	*node;

	node = a->first;
	if (node == NULL)
		return (0);
	else
	{
		while (node->next)
		{
			if (node->nb > node->next->nb)
				return (0);
			node = node->next;
		}
		return (1);
	}
}
