#include "push_swap.h"

int ft_chunk_search(t_List *List, int chunk)
{
	t_element	*tmp;

	tmp = List->top;
	while (tmp)
	{
		if (tmp->chunk == chunk)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	min_value(int n1, int n2, int n3)
{
	if (ft_abs(n1) <= ft_abs(n2) && ft_abs(n1) <= ft_abs(n3))
		return (n1);
	else if (ft_abs(n2) <= ft_abs(n1) && ft_abs(n2) <= ft_abs(n3))
		return (n2);

	return (n3);
}

int	get_chunk_index(t_List *List, int chunk)
{
	t_element	*tmp;

	if (!List->top)
		return (INT_MAX);
	tmp = List->top;

	while (tmp && tmp->chunk != chunk)
		tmp = tmp->next;
	if (!tmp)
		return (INT_MAX);
	return(get_index(tmp->value, List));
}

int	get_chunk_index_me(t_List *List, int chunk)
{
	t_element	*tmp;
	int			n1;
	int			n2;

	if (!List->top)
		return (INT_MAX);
	tmp = List->top;

	while (tmp && tmp->chunk != chunk)
		tmp = tmp->next;
	if (!tmp)
		return (INT_MAX);
	n1 = get_index(tmp->value, List);

	while (tmp->next && tmp->next->chunk == chunk)
		tmp = tmp->next;
	if (!tmp)
		return (INT_MAX);
	n2 = get_index(tmp->value, List);
	if (ft_abs(n1) < ft_abs(n2))
		return (n1);
	return (n2);
}

int	nearest_chunk_target(t_List *List, int chunk)
{
	int		n1;
	int		n2;
	int		n3;
	//int		x;

	if (!List->top)
		return (0);
	n1 = get_chunk_index_me(List, chunk);
	if (n1 != INT_MAX)
		return (n1);
	n2 = get_chunk_index(List, chunk - 1);
	n3 = get_chunk_index(List, chunk - 2);
	
	//printf("\nN1 : %d, N2 : %d, N3 : %d -------> min : %d\n", n1, n2, n3, min_value(n1, n2, n3));
	//scanf("%d", &x);
	if (n1 == INT_MAX && n2 == INT_MAX && n3 == INT_MAX)
		return (0);
	return (min_value(n1, n2, n3));
}

void	go_to_chunk_target(t_List *List_b, int	chunk)
{
	int			target;

	target = nearest_chunk_target(List_b, chunk);
	while (target)
	{
		if (target > 0)
		{
			target--;
			rb(List_b);
		}
		else if (target < 0)
		{
			target++;
			rrb(List_b);
		}
	}
}



void	get_next(t_List *List_a, t_List *List_b, int chunk)
{
	t_element	*tmp;
	int			index;
	int			target;

	tmp = List_a->top;
	if (chunk % 2 == 1 && !ft_chunk_search(List_b, chunk))
		while (tmp && tmp->chunk != chunk)
			tmp = tmp->next;
	else
		while (tmp && tmp->chunk != chunk && tmp->chunk != chunk + 1)
			tmp = tmp->next;	
	if (!tmp)
		return ;
	index = get_index(tmp->value, List_a);
	target = nearest_chunk_target(List_b, tmp->chunk);
	while (index)
	{
		if (index > 0 && target > 0)
		{
			rr(List_a, List_b);
			index--;
			target--;
		}
		else if (index < 0 && target < 0)
		{
			rrr(List_a, List_b);
			index++;
			target++;
		}
		else if (index > 0)
		{
			ra(List_a);
			index--;
		}
		else if(index < 0)
		{
			rra(List_a);
			index++;
		}
	}

}

void    ft_lst_pre_sort(t_List *List_a, t_List *List_b)
{
	t_element   *tmp_a;
	int         i_chunk;

	if (!List_a || !List_a->top || !List_a->top->next)
		return ;
	i_chunk = 1;
	while (i_chunk < 6)
	{
		tmp_a = List_a->top;
		if (!tmp_a)
			return ;
		while (tmp_a && ft_lstsize(List_a) > 2 && (ft_chunk_search(List_a, i_chunk) || ft_chunk_search(List_a, i_chunk + 1)))
		{
			//printf("tmp : %d, chunk : %d, i : %d\n", tmp_a->value, tmp_a->chunk, i_chunk);
			if (tmp_a->chunk == i_chunk || tmp_a->chunk == i_chunk + 1)
			{		
				go_to_chunk_target(List_b, tmp_a->chunk);
				pb(List_a, List_b);
			}
			else
				get_next(List_a, List_b, i_chunk);
			tmp_a = List_a->top;			
		}
		i_chunk = i_chunk + 2;
	}
}