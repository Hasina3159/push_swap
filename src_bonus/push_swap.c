#include "push_swap.h"

int	is_sorted(t_List *List)
{
	t_element	*tmp;

	if (!List || !List->top)
		return (0);
	tmp = List->top;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	small_sort(t_List *List_a)
{
	t_element	*tmp;

	if (ft_lstsize(List_a) <= 1)
		return ;
	tmp = List_a->top;
	if (ft_lstsize(List_a) == 2 && tmp->value > tmp->next->value)
		sa(List_a);
	else if (ft_lstsize(List_a) == 3)
		ft_three_sort(List_a);
}

void	ft_lstfree(t_List *List)
{
	t_element	*tmp;
	t_element	*tmp1;

	tmp = List->top;
	tmp1 = tmp->next;
	while (tmp->next)
	{
		free(tmp);
		tmp = tmp1;
		tmp1 = tmp->next;
	}
	free(tmp);
}

void	all_move(t_List *a, t_List *b)
{
	a->array = create_array(a);
	sort_array(a->array);
	b->top = NULL;
	move_all_necessary(a, b);
	go_to_max(b, 'b');
	ft_three_sort(a);
	finish_move(a, b);
	free(a);
	free(b);
}

int	main(int argc, char **argv)
{
	t_List		*a;
	t_List		*b;

	if (argc > 1)
	{
		if (!error_check(argv))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		b = (t_List *)malloc(sizeof(t_List));
		a = input_to_list(argv);
		if (!b || !a || !a->top || !a->top->next || is_sorted(a))
			return (free(a), free(b), 0);
		if (ft_lstsize(a) <= 3)
			small_sort(a);
		else if (ft_lstsize(a) <= 100)
			all_move(a, b);
		else
			all_move_500(a, b);
	}
	return (0);
}
