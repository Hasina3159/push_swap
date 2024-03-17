/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghost <ghost@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:19:51 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/03/17 14:52:18 by ghost            ###   ########.fr       */
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

int 		error_check(char **s);
long		ft_atoi(const char *str);
int			ft_get_min(t_List *List);
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