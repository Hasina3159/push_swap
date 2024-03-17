#include "push_swap.h"

int ft_lstsize(t_List *List)
{
	int         i;
	t_element   *tmp;

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

int ft_get_min(t_List *List)
{
	t_element   *tmp;
	int         i;
	int         min;
	int         imin;

	i = 0;
	imin = 0;
	tmp = List->top;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			imin = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (imin);
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

void	go_to_min(t_List *List, char stack)
{
	int			size;
	int			min;
	int			forward;
	int			backward;

	size = ft_lstsize(List);
	if (size == 0)
		return ;
	min = ft_get_min(List);
	forward = min;
	backward = size - min;
	if (forward > backward)
		min_backward(List, backward, stack);
	else
		min_forward(List, forward, stack);
}