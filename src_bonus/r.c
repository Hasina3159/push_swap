/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:20:53 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/03/25 13:55:59 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	r(t_List *List)
{
	int			value;
	t_element	*tmp;

	if (!List || !List->top || !List->top->next)
		return ;
	tmp = List->top;
	value = tmp->value;
	while (tmp->next)
	{
		tmp->value = tmp->next->value;
		tmp = tmp->next;
	}
	tmp->value = value;
}

void	ra(t_List *List_a)
{
	r(List_a);
}

void	rb(t_List *List_b)
{
	r(List_b);
}

void	rr(t_List *List_a, t_List *List_b)
{
	r(List_a);
	r(List_b);
}
