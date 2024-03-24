#include "push_swap.h"

static void	ft_condition(int *infos, t_List *List_a, t_List *List_b)
{
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
}

static void	ft_condition_1(int *infos, t_List *List_a, t_List *List_b)
{
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

void	move_all_necessary(t_List *List_a, t_List *List_b)
{
	int			*infos;
	t_element	*tmp;

	while (ft_lstsize(List_a) > 3 && ft_lstsize(List_a) > List_a->size - 2)
	{
		tmp = List_a->top;
		if (is_three_last(List_a, tmp->value))
			ra(List_a);
		else
			pb(List_a, List_b);
	}
	while (ft_lstsize(List_a) > 3)
	{
		infos = get_min_cost(List_a, List_b);
		while (infos[1] > 0 && infos[2] > 0)
		{
			rr(List_a, List_b);
			infos[1] = infos[1] - 1;
			infos[2] = infos[2] - 1;
		}
		ft_condition(infos, List_a, List_b);
		ft_condition_1(infos, List_a, List_b);
	}
}

void	move_all_necessary_500(t_List *List_a, t_List *List_b)
{
	int			*infos;
	t_element	*tmp;

	while (ft_lstsize(List_a) > 3 && ft_lstsize(List_a) > List_a->size - 2)
	{
		tmp = List_a->top;
		if (is_three_last(List_a, tmp->value))
			ra(List_a);
		else
			pb(List_a, List_b);
	}
	while (ft_lstsize(List_a) > 3)
	{
		infos = get_min_cost(List_a, List_b);
		while (infos[1] > 0 && infos[2] > 0)
		{
			rr(List_a, List_b);
			infos[1] = infos[1] - 1;
			infos[2] = infos[2] - 1;
		}
		ft_condition(infos, List_a, List_b);
		ft_condition_1(infos, List_a, List_b);
	}
}
