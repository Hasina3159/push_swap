#include "push_swap.h"

static void	r(t_List *List)
{
	int			value;
	t_element	*tmp;

	if (!List || !List->top || !List->top->next)
		return ;
	tmp = List->top;
	value = tmp->value;
	while (tmp->next)
	{
		tmp->value = tmp->next->value;
		tmp = tmp->next;
	}
	tmp->value = value;
}

void    ra(t_List *List_a)
{
	r(List_a);
	ft_putstr("ra");
}

void    rb(t_List *List_b)
{
	r(List_b);
	ft_putstr("rb");
}

void    rr(t_List *List_a, t_List *List_b)
{
	r(List_a);
	r(List_b);
	ft_putstr("rr");
}