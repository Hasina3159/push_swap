#include "push_swap.h"

int ft_check_sorted(t_List *List)
{
	t_element   *tmp;

	tmp = List->top;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void    ft_lstsort(t_List *List_a, t_List *List_b)
{
	if (!List_a || !List_a->top || !List_a->top->next)
		return ;
	while (!ft_check_sorted(List_a) && ft_lstsize(List_a) > 1)
	{
		go_to_min(List_a, 'a');
		pb(List_a, List_b);
	}
	while (ft_lstsize(List_b))
	{
		pa(List_b, List_a);
	}
}
