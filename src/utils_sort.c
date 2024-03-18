#include "push_swap.h"

int	get_b_bijection(long n_a, t_List *List_b)
{
	long		nbr;
	t_element	*tmp;

	nbr = LONG_MIN;
	tmp = List_b->top;
	while (tmp)
	{
		if ((tmp->value < n_a) && (n_a - tmp->value < n_a - nbr))
			nbr = tmp->value;
		tmp = tmp->next;
	}
	if (nbr == LONG_MIN)
		nbr = ft_get_max(List_b);
	return ((int) nbr);
}

int	get_a_bijection(long n_b, t_List *List_a)
{
	long		nbr;
	t_element	*tmp;

	nbr = LONG_MAX;
	tmp = List_a->top;
	while (tmp)
	{
		if ((tmp->value > n_b) && (tmp->value - n_b < nbr - n_b))
			nbr = tmp->value;
		tmp = tmp->next;
	}
	if (nbr == LONG_MAX)
		nbr = ft_get_max(List_a);
	return ((int) nbr);
}

int	get_index(int n, t_List *List)
{
	int			index;
	int			i;
	t_element	*tmp;

	index = 0;
	i = 0;
	tmp = List->top;
	while (tmp)
	{
		if (tmp->value == n)
		{
			index = i;
			break;
		}
		i++;
		tmp = tmp->next;
	}
	if (index <= ft_lstsize(List) / 2)
		return (index);
	return (0 - (ft_lstsize(List) - index));
}

int	get_cost(int n, t_List *List_1, t_List *List_2, char type)
{
	int cost1;
	int cost2;

	cost1 = get_index(n, List_1);
	if (type == 'a')
		cost2 = get_index(get_a_bijection(n, List_2), List_2);
	else
		cost2 = get_index(get_b_bijection(n, List_2), List_2);
	return (ft_abs(cost2 - cost1));
}

int	*get_min_cost(t_List *List1, t_List *List2, char type)
{
	int			min_cost;
	int         move_1;
	int         move_2;
	int			*final;
	t_element	*tmp;

	move_1 = 0;
	move_2 = 0;
	min_cost = INT_MAX;
	final = (int *)malloc(sizeof(int) * 3);
	if (!final)
		return (NULL); 
	tmp = List1->top;
	while (tmp)
	{
		if (get_cost(tmp->value, List1, List2, type) < min_cost)
		{
			min_cost = get_cost(tmp->value, List1, List2, type);
			move_1 = get_index(tmp->value, List1);
			if (type == 'a')
				move_2 = get_index(get_a_bijection(tmp->value, List2), List2);
			else
				move_2 = get_index(get_b_bijection(tmp->value, List2), List2);
		}
		tmp = tmp->next;
	}
	final[0] = min_cost;
	final[1] = move_1;
	final[2] = move_2;
	return (final);
}



void	move_all_necessary(t_List *List_a, t_List *List_b, char type)
{
	int			*infos;

	if (ft_lstsize(List_a) >= 5)
	{
		pb(List_a, List_b);
		pb(List_a, List_b);
	}

	while (ft_lstsize(List_a) > 0)
	{
		infos = get_min_cost(List_a, List_b, type);
		while (infos[1] > 0 && infos[2] > 0)
		{
			rr(List_a, List_b);
			infos[1] = infos[1] - 1;
			infos[2] = infos[2] - 1;
		}
		while (infos[1] < 0 && infos[2] < 0)
		{
			rrr(List_a, List_b);
			infos[1] = infos[1] + 1;
			infos[2] = infos[2] + 1;
		}
		while (infos[1] > 0)
		{
			ra(List_a);
			infos[1] = infos[1] - 1;
		}
		while (infos[2] > 0)
		{
			rb(List_b);
			infos[2] = infos[2] - 1;
		}
		while (infos[1] < 0)
		{
			rra(List_a);
			infos[1] = infos[1] + 1;
		}
		while (infos[2] < 0)
		{
			rrb(List_b);
			infos[2] = infos[2] + 1;
		}
		pb(List_a, List_b);
	}
}

void	move_all_necessary_f(t_List *List_a, t_List *List_b)
{
	while (ft_lstsize(List_b) > 0)
		pa(List_b, List_a);
}


void	ft_three_sort(t_List *List_a)
{
	t_element	*first;

	first = List_a->top;
	if (ft_get_max(List_a) == first->value)
		ra(List_a);
	else if (ft_get_max(List_a) == first->next->value)
		rra(List_a);
	if (first->value > first->next->value)
		sa(List_a);
}
