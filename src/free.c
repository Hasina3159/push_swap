/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:22:37 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/03/25 15:26:04 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_element *top)
{
	if (top->next)
		free_list(top->next);
	if (top)
		free(top);
}

void	free_all(t_List *List)
{
	if (!List)
		return ;
	if (List->array)
		free(List->array);
	if (List->top)
		free_list(List->top);
	free(List);
}
