/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:46:04 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/20 09:56:20 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_min_second(t_nblist *a)
{
	if (a->first->nb < a->first->next->next->nb)
	{
		ft_reverse_rotate_list(a);
		ft_putstr_fd("rra\n", 1);
		ft_swap_list(a);
		ft_putstr_fd("sa\n", 1);
	}
	else
	{
		ft_reverse_rotate_list(a);
		ft_putstr_fd("rra\n", 1);
	}
}

void	algo_min(t_nblist *a)
{
	if (a->first->nb > a->first->next->nb
		&& a->first->next->nb > a->first->next->next->nb)
	{
		ft_swap_list(a);
		ft_putstr_fd("sa\n", 1);
		ft_reverse_rotate_list(a);
		ft_putstr_fd("rra\n", 1);
	}
	else if (a->first->nb > a->first->next->nb
		&& a->first->next->nb < a->first->next->next->nb)
	{
		if (a->first->nb > a->first->next->next->nb)
		{
			ft_rotate_list(a);
			ft_putstr_fd("ra\n", 1);
		}
		else
		{
			ft_swap_list(a);
			ft_putstr_fd("sa\n", 1);
		}
	}
	else if (a->first->nb < a->first->next->nb
		&& a->first->next->nb > a->first->next->next->nb)
		algo_min_second(a);
}

void	chose_algo(t_nblist *a, t_nblist *b, t_data *data)
{
	if (ft_is_sort(a))
		return ;
	if (data->size_a == 2 && a->first->nb > a->first->next->nb)
	{			
		ft_swap_list(a);
		ft_putstr_fd("sa\n", 1);
		return ;
	}
	if (data->size_a <= 3)
		algo_min(a);
	else
		radix_sort(a, b, data);
}
