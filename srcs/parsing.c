/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:38:54 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/17 12:40:19 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_double(int nb, t_nblist *a)
{
	t_node	*nbr;

	nbr = a->first;
	while (nbr)
	{
		if (nbr->nb == nb)
			return (0);
		nbr = nbr->next;
	}
	return (1);
}

int	check_nbr(char *str, t_nblist *a)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
		return (0);
	if (!check_double(ft_atoi(str), a))
		return (0);
	return (1);
}
