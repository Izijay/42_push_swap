/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:55:05 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/17 12:40:15 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_list(t_nblist *list)
{
	int	tmp;

	if (!list || list->first == NULL || list->last == NULL)
		return ;
	else
	{
		tmp = list->first->nb;
		list->first->nb = list->first->next->nb;
		list->first->next->nb = tmp;
	}
}

void	ft_pb_list(t_nblist *list_push, t_nblist *list_pull, t_data *data)
{
	t_node	*push;

	if (!list_push && !list_push->first)
		return ;
	push = list_push->first;
	list_push->first = push->next;
	if (!list_pull->first || !list_pull->last)
	{
		push->next = NULL;
		list_pull->first = push;
		list_pull->last = push;
	}
	else
	{
		push->next = list_pull->first;
		list_pull->first = push;
	}
	data->size_a -= 1;
	data->size_b += 1;
	ft_putstr_fd("pb\n", 1);
}

void	ft_pa_list(t_nblist *list_push, t_nblist *list_pull, t_data *data)
{
	t_node	*push;

	if (!list_push && !list_push->first)
		return ;
	push = list_push->first;
	list_push->first = push->next;
	if (!list_pull->first || !list_pull->last)
	{
		push->next = NULL;
		list_pull->first = push;
		list_pull->last = push;
	}
	else
	{
		push->next = list_pull->first;
		list_pull->first = push;
	}
	data->size_a += 1;
	data->size_b -= 1;
	ft_putstr_fd("pa\n", 1);
}

void	ft_rotate_list(t_nblist *list)
{
	t_node	*rotate;

	if (!list)
		return ;
	rotate = list->first;
	list->first = list->first->next;
	list->last->next = rotate;
	rotate->next = NULL;
	list->last = rotate;
}

void	ft_reverse_rotate_list(t_nblist *list)
{
	t_node	*tmp;

	if (!list->first || !list->last)
		return ;
	tmp = list->first;
	while (tmp->next != list->last)
		tmp = tmp->next;
	tmp->next->next = list->first;
	list->first = tmp->next;
	tmp->next = NULL;
	list->last = tmp;
}
