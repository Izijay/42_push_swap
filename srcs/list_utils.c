/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:50:21 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/21 13:37:00 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_nblist	*init_list(t_nblist *new)
{
	new = malloc(sizeof(t_nblist));
	if (new == NULL)
		return (0);
	new->first = NULL;
	new->last = NULL;
	return (new);
}

int	copy_node(t_nblist *copy, int nb)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (0);
	node->nb = nb;
	node->next = NULL;
	if (!copy->first || !copy->last)
	{
		copy->first = node;
		copy->last = node;
	}
	else
	{
		copy->last->next = node;
		copy->last = node;
	}
	return (1);
}

void	copy_list(t_nblist *a, t_nblist *copy)
{
	t_node	*tmp;

	tmp = a->first;
	while (tmp)
	{
		copy_node(copy, tmp->nb);
		tmp = tmp->next;
	}
}

t_nblist	*list_del(t_nblist *list)
{
	t_node	*node;
	t_node	*tmp;

	node = list->first;
	while (node != NULL)
	{
		tmp = node;
		node = tmp->next;
		free(tmp);
	}
	free(list);
	return (NULL);
}

int	add_to_list(t_nblist *a, int nb, int *a_size)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (0);
	node->nb = nb;
	node->next = NULL;
	if (a->first == NULL)
	{
		a->first = node;
		a->last = node;
	}
	else
	{
		a->last->next = node;
		a->last = node;
	}
	*a_size += 1;
	return (1);
}
