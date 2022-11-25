/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:41:09 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/21 15:38:15 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_nblist	*sort_copy(t_nblist *copy)
{
	t_node	*node;
	int		nbr;

	node = copy->first;
	nbr = 0;
	while (node != copy->last)
	{
		if (node->nb > node->next->nb)
		{
			nbr = node->nb;
			node->nb = node->next->nb;
			node->next->nb = nbr;
			node = copy->first;
		}
		else
			node = node->next;
	}
	return (copy);
}

void	bubble_sort_list(t_nblist *copy, t_nblist *a)
{
	t_node	*i;
	t_node	*j;
	int		k;

	i = a->first;
	while (i <= a->last)
	{
		j = copy->first;
		k = 0;
		while (j <= copy->last)
		{
			if (i->nb == j->nb)
			{
				i->nb = k;
				break ;
			}
			j = j->next;
			k++;
		}
		if (i == a->last)
			break ;
		i = i->next;
	}
}

void	algo_radix_sort(t_nblist *a, t_nblist *b, t_data *data)
{
	int	n_elem;
	int	i;
	int	j;
	int	nb;

	i = 0;
	n_elem = data->size_a;
	while (!ft_is_sort(a))
	{
		j = -1;
		while (++j < n_elem)
		{
			nb = a->first->nb;
			if ((nb >> i) & 1)
			{
				ft_putstr_fd("ra\n", 1);
				ft_rotate_list(a);
			}
			else
				ft_pb_list(a, b, data);
		}
		while (data->size_b > 0)
			ft_pa_list(b, a, data);
		i++;
	}
}

void	radix_sort(t_nblist *a, t_nblist *b, t_data *data)
{
	t_nblist	*copy;

	copy = NULL;
	copy = init_list(copy);
	copy_list(a, copy);
	copy = sort_copy(copy);
	bubble_sort_list(copy, a);
	if (data->size_a == 5)
		algo_five(a, b, data);
	else
		algo_radix_sort(a, b, data);
	copy = list_del(copy);
}
