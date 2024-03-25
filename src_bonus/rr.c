/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:20:56 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/03/25 14:19:57 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_element	*get_last(t_List *List)
{
	t_element	*tmp;

	if (!List || !List->top)
		return (NULL);
	tmp = List->top;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

static void	r(t_List *List)
{
	int			value;
	int			tmp_1v;
	int			tmp_2v;
	t_element	*tmp;

	if (!List || !List->top || !List->top->next)
		return ;
	tmp = List->top;
	value = get_last(List)->value;
	tmp_1v = tmp->value;
	tmp_2v = tmp->next->value;
	while (tmp->next)
	{
		tmp->next->value = tmp_1v;
		tmp_1v = tmp_2v;
		tmp = tmp->next;
		if (tmp->next)
			tmp_2v = tmp->next->value;
	}
	List->top->value = value;
}

void	rra(t_List *List_a)
{
	r(List_a);
}

void	rrb(t_List *List_b)
{
	r(List_b);
}

void	rrr(t_List *List_a, t_List *List_b)
{
	r(List_a);
	r(List_b);
}
