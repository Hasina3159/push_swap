/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:20:33 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/03/25 15:26:24 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_List *List)
{
	t_element	*tmp;

	if (!List || !List->top)
		return (0);
	tmp = List->top;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	small_sort(t_List *List_a)
{
	t_element	*tmp;

	if (ft_lstsize(List_a) <= 1)
		return ;
	tmp = List_a->top;
	if (ft_lstsize(List_a) == 2 && tmp->value > tmp->next->value)
		sa(List_a);
	else if (ft_lstsize(List_a) == 3)
		ft_three_sort(List_a);
}

void	ft_lstfree(t_List *List)
{
	t_element	*tmp;
	t_element	*tmp1;

	tmp = List->top;
	tmp1 = tmp->next;
	while (tmp->next)
	{
		free(tmp);
		tmp = tmp1;
		tmp1 = tmp->next;
	}
	free(tmp);
}

void	ft_condition(t_List *a, t_List *b)
{
	if (ft_lstsize(a) <= 3)
		small_sort(a);
	else if (ft_lstsize(a) <= 100)
		all_move(a, b);
	else
		all_move_500(a, b);
}

int	main(int argc, char **argv)
{
	t_List		*a;
	t_List		*b;
	char		**av;

	if (argc > 1)
	{
		av = argv;
		if (argc == 2)
			av = ft_split(argv[1], ' ');
		if (!error_check(av))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		b = (t_List *)malloc(sizeof(t_List));
		a = input_to_list(av);
		free_split(av);
		if (!b || !a || !a->top || !a->top->next || is_sorted(a))
			return (free_all(a), free(b), 0);
		ft_condition(a, b);
	}
	return (0);
}
