/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:21:20 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/03/25 15:26:30 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_check_sorted(t_List *List)
{
	t_element	*tmp;

	tmp = List->top;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_lstsort(t_List *List_a, t_List *List_b)
{
	if (!List_a || !List_a->top || !List_a->top->next)
		return ;
	while (!ft_check_sorted(List_a) && ft_lstsize(List_a) > 1)
	{
		go_to_min(List_a, 'a');
		pb(List_a, List_b);
	}
	while (ft_lstsize(List_b))
	{
		pa(List_b, List_a);
	}
}

void	go_to_min(t_List *List, char stack)
{
	int	min;

	min = get_index(ft_get_min(List), List);
	if (min < 0)
		min_backward(List, ft_abs(min), stack);
	else if (min > 0)
		min_forward(List, ft_abs(min), stack);
}

void	go_to_max(t_List *List, char stack)
{
	int	max;

	max = get_index(ft_get_max(List), List);
	if (max < 0)
		min_backward(List, ft_abs(max), stack);
	else if (max > 0)
		min_forward(List, ft_abs(max), stack);
}
