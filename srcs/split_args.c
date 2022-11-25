/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:52:41 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/21 11:08:25 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strlen_tab2d(char **tab)
{
	int	i;

	i = 0;
	while (tab[i++])
		;
	return (i);
}

char	**split_args(t_nblist *a, t_nblist *b, t_data *data, char *str)
{
	char	**tab;
	int		size;

	tab = ft_split(str, ' ');
	if (tab == NULL)
		return (NULL);
	size = ft_strlen_tab2d(tab) - 1;
	data->i = 0;
	if (!list_fill(size, a, tab, data))
	{
		a = list_del(a);
		b = list_del(b);
		ft_free_tab2d(tab);
		return (NULL);
	}
	return (tab);
}
