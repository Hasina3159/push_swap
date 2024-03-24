/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghost <ghost@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:19:46 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/03/24 16:12:12 by ghost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	s(t_List *List)
{
	int			tmp;
	t_element	*first;
	t_element	*second;

	if (List && List->top && List->top->next)
	{
		first = List->top;
		second = List->top->next;
		tmp = first->value;
		first->value = second->value;
		second->value = tmp;
	}
}

void	sa(t_List *List_a)
{
	s(List_a);
	ft_putstr("sa");
}

void	sb(t_List *List_b)
{
	s(List_b);
	ft_putstr("sb");
}

void	ss(t_List *List_a, t_List *List_b)
{
	s(List_a);
	s(List_b);
	ft_putstr("ss");
}
