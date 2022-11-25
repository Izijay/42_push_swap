/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:30:20 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/21 13:38:18 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_struct(t_data *data)
{
	data->size_a = 0;
	data->size_b = 0;
	data->i = 1;
}

void	ft_exit(t_nblist *a, t_nblist *b, char **tab)
{
	a = list_del(a);
	b = list_del(b);
	if (tab != NULL)
		ft_free_tab2d(tab);
}

int	ft_exit_error(t_nblist *a, t_nblist *b)
{
	a = list_del(a);
	b = list_del(b);
	return (1);
}

int	list_fill(int ac, t_nblist *a, char **av, t_data *data)
{
	int	nb;

	while (data->i < ac)
	{
		if (!check_nbr(av[data->i], a))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		nb = ft_atoi(av[data->i]);
		if (!add_to_list(a, nb, &data->size_a))
			return (0);
		data->i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_nblist	*a;
	t_nblist	*b;
	t_data		data;
	char		**tab;

	a = NULL;
	b = NULL;
	tab = NULL;
	if (ac == 1)
		return (0);
	init_struct(&data);
	a = init_list(a);
	b = init_list(b);
	if (ac == 2)
	{
		tab = split_args(a, b, &data, av[1]);
		if (tab == NULL)
			return (1);
	}
	if (ac > 2 && (!list_fill(ac, a, av, &data)))
		return (ft_exit_error(a, b));
	chose_algo(a, b, &data);
	ft_exit(a, b, tab);
	return (0);
}
