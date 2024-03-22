/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghost <ghost@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:19:51 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/03/22 18:50:01 by ghost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct	s_element
{
	int					value;
	struct s_element	*next;
}						t_element;

typedef struct	s_List
{
	t_element	*top;
}				t_List;

int	get_b_bijection(long n_a, t_List *List_b);
int	get_a_bijection(long n_b, t_List *List_a);
int	get_index(int n, t_List *List);
int	get_cost(int n, t_List *List_1, t_List *List_2, char type);
int	*get_min_cost(t_List *List1, t_List *List2, char type);
void	move_all_necessary(t_List *List_a, t_List *List_b, char type);
void	move_all_necessary_f(t_List *List_a, t_List *List_b);
void	show_values(t_List *List);
void	move_all(t_List *List_a, t_List *List_b, char type);
void	ft_three_sort(t_List *List_a);

void	finish_move(t_List *List_a, t_List *List_b);
int 		error_check(char **s);
int			ft_abs(int n);
long		ft_atoi(const char *str);
int			ft_get_min(t_List *List);
int			ft_get_max(t_List *List);
int			ft_lstsize(t_List *List);
void		ft_lstsort(t_List *List_a, t_List *List_b);
void		ft_putstr(char *s);
void		push_to_end(t_List *List, char *s);
void		go_to_min(t_List *List, char stack);
void		sa(t_List *List_a);
void		sb(t_List *List_b);
void		ss(t_List *List_a, t_List *List_b);
void		pa(t_List *List_b, t_List *List_a);
void		pb(t_List *List_a, t_List *List_b);
void		ra(t_List *List_a);
void		rb(t_List *List_b);
void		rr(t_List *List_a, t_List *List_b);
void		rra(t_List *List_a);
void		rrb(t_List *List_b);
void		rrr(t_List *List_a, t_List *List_b);
t_List		*input_to_list(char **argv);
t_element	*ft_lstnew(int value);
t_element	*get_last(t_List *List);

#endif