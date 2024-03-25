/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:20:30 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/03/25 15:26:24 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_low_med(t_List *List)
{
	t_element	*tmp;

	tmp = List->top;
	while (tmp)
	{
		if (tmp->value < List->median)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	to_b(t_List *a, t_List *b)
{
	while (is_low_med(a) > 0)
	{
		if (a->top->value < a->median)
			pb(a, b);
		else
			ra(a);
	}
	while (ft_lstsize(b) > 0)
		pa(b, a);
}

void	all_move(t_List *a, t_List *b)
{
	a->array = create_array(a);
	sort_array(a->array);
	b->top = NULL;
	move_all_necessary(a, b);
	go_to_max(b, 'b');
	ft_three_sort(a);
	finish_move(a, b);
	if (a)
		free_all(a);
	free(b);
}

void	all_move_500(t_List *a, t_List *b)
{
	a->array = create_array(a);
	sort_array(a->array);
	a->size = ft_lstsize(a);
	a->median = a->array[a->size / 2];
	b->top = NULL;
	to_b(a, b);
	move_all_necessary_500(a, b);
	go_to_max(b, 'b');
	ft_three_sort(a);
	rra(a);
	rra(a);
	rra(a);
	finish_move(a, b);
	if (a)
		free_all(a);
	free(b);
}

void	free_split(char **av)
{
	int	i;

	if (!av)
		return ;
	free(av[0]);
	i = 1;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
