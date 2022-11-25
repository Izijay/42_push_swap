/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:30:22 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/21 14:20:11 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int					size_a;
	int					size_b;
	int					i;
}						t_data;

typedef struct s_node
{
	int					nb;
	struct s_node		*next;
}						t_node;

typedef struct s_nblist
{
	t_node				*first;
	t_node				*last;
}						t_nblist;

t_nblist	*init_list(t_nblist *new);
t_nblist	*list_del(t_nblist *list);
t_nblist	*init_list(t_nblist *new);
void		ft_swap_list(t_nblist *list);
void		ft_reverse_rotate_list(t_nblist *list);
void		ft_rotate_list(t_nblist *list);
void		ft_pa_list(t_nblist *list_push, t_nblist *list_pull, t_data *data);
void		ft_pb_list(t_nblist *list_push, t_nblist *list_pull, t_data *data);
void		chose_algo(t_nblist *a, t_nblist *b, t_data *data);
void		radix_sort(t_nblist *a, t_nblist *b, t_data *data);
void		copy_list(t_nblist *a, t_nblist *copy);
void		algo_min(t_nblist *a);
void		algo_five(t_nblist *a, t_nblist *b, t_data *data);
char		**split_args(t_nblist *a, t_nblist *b, t_data *data, char *str);
int			check_nbr(char *str, t_nblist *a);
int			copy_node(t_nblist *copy, int nb);
int			ft_is_sort(t_nblist *a);
int			list_fill(int ac, t_nblist *a, char **av, t_data *data);
int			add_to_list(t_nblist *a, int nb, int *a_size);

#endif
