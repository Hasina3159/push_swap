#include "push_swap.h"

static void	push(t_List *List_src, t_List *List_dst)
{
	t_element	*tmp;

	if (!List_src || !List_src->top)
		return ;
	tmp = List_src->top;
	List_src->top = tmp->next;
	tmp->next = List_dst->top;
	List_dst->top = tmp;
}

void	pa(t_List *List_b, t_List *List_a)
{
	ft_putstr("pa");
	push(List_b, List_a);
}

void	pb(t_List *List_a, t_List *List_b)
{
	ft_putstr("pb");
	push(List_a, List_b);
}
