#include "push_swap.h"

int	ft_lstsize(t_List *List)
{
	int			i;
	t_element	*tmp;

	i = 0;
	if (!List || !List->top)
		return (0);
	tmp = List->top;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_get_min(t_List *List)
{
	t_element	*tmp;
	int			i;
	int			min;

	i = 0;
	tmp = List->top;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		i++;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_get_max(t_List *List)
{
	t_element	*tmp;
	int			i;
	int			max;

	i = 0;
	tmp = List->top;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		i++;
		tmp = tmp->next;
	}
	return (max);
}

void	min_forward(t_List *List, int step, char stack)
{
	int			i;

	i = 0;
	while (i < step)
	{
		if (stack == 'a')
			ra(List);
		else
			rb(List);
		i++;
	}
}

void	min_backward(t_List *List, int step, char stack)
{
	int			i;

	i = 0;
	while (i < step)
	{
		if (stack == 'a')
			rra(List);
		else
			rrb(List);
		i++;
	}
}
