/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:35:16 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/21 09:48:22 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_five_second(t_nblist *a, t_nblist *b, t_data *data)
{
	if (b->first->nb < b->first->next->nb)
	{
		ft_swap_list(b);
		ft_putstr_fd("sb\n", 1);
	}
	if (!ft_is_sort(a))
		algo_min(a);
	while (data->size_b > 0)
		ft_pa_list(b, a, data);
}

void	algo_five(t_nblist *a, t_nblist *b, t_data *data)
{
	int		i;

	i = 0;
	while (1)
	{
		if (i == 2)
			break ;
		if (a->first->nb < 2)
		{
			ft_pb_list(a, b, data);
			i++;
		}
		else
		{
			ft_rotate_list(a);
			ft_putstr_fd("ra\n", 1);
		}
	}
	algo_five_second(a, b, data);
}
