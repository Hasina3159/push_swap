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
		nbr = ft_get_min(List_a);
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
			break ;
		}
		i++;
		tmp = tmp->next;
	}
	if (index <= ft_lstsize(List) / 2)
		return (index);
	return (0 - (ft_lstsize(List) - index));
}

int	get_cost(int n, t_List *List_1, t_List *List_2)
{
	int	cost1;
	int	cost2;

	if (is_three_last(List_1, n))
		return (INT_MAX);
	cost1 = get_index(n, List_1);
	cost2 = get_index(get_a_bijection(n, List_2), List_2);
	return (ft_abs(cost2) + ft_abs(cost1));
}
