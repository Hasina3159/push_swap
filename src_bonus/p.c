/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:20:27 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/03/25 13:55:49 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push(t_List *List_src, t_List *List_dst)
{
	t_element	*tmp;

	if (!List_src || !List_src->top)
		return ;
	tmp = List_src->top;
	List_src->top = tmp->next;
	tmp->next = List_dst->top;
	List_dst->top = tmp;
}

void	pa(t_List *List_b, t_List *List_a)
{
	push(List_b, List_a);
}

void	pb(t_List *List_a, t_List *List_b)
{
	push(List_a, List_b);
}
