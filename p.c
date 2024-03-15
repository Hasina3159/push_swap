#include "push_swap.h"

static void	push(t_List *List_src, t_List *List_dst)
{
	t_element	*new;
	t_element	*tmp;
	t_element	*tmp1;

	if (!List_src || !List_src->top)
		return ;
	tmp = List_src->top;
	List_src->top = tmp->next;
	tmp->next = NULL;

	if (List_dst->top == NULL)
	{
		List_dst->top = tmp;
		return ;
	}
	tmp1 = List_dst->top;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp1->next = tmp;
}

void	pa(t_List *List_b, t_List *List_a)
{
	push(List_b, List_a);
	ft_putstr("pa");
}

void	pb(t_List *List_a, t_List *List_b)
{
	push(List_a, List_b);
	ft_putstr("pb");
}
