#include "push_swap.h"

void	finish_move(t_List *List_a, t_List *List_b)
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

int	is_three_last(t_List *List, int n)
{
	int	*array;
	int	size;

	array = List->array;
	size = List->size;
	if (n == array[size] || n == array[size - 1] || n == array[size - 2])
		return (1);
	return (0);
}

int	*get_min_cost(t_List *List1, t_List *List2)
{
	int			min_cost;
	int			*final;
	t_element	*tmp;

	min_cost = INT_MAX;
	final = (int *)malloc(sizeof(int) * 3);
	if (!final)
		return (NULL);
	tmp = List1->top;
	while (tmp)
	{
		if (get_cost(tmp->value, List1, List2) < min_cost)
		{
			min_cost = get_cost(tmp->value, List1, List2);
			final[1] = get_index(tmp->value, List1);
			final[2] = get_index(get_b_bijection(tmp->value, List2), List2);
		}
		tmp = tmp->next;
	}
	final[0] = min_cost;
	return (final);
}
