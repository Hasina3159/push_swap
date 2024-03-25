/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:19:46 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/03/25 13:56:12 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

void	sb(t_List *List_b)
{
	s(List_b);
}

void	ss(t_List *List_a, t_List *List_b)
{
	s(List_a);
	s(List_b);
}
