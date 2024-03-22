#include "push_swap.h"


void	show_values(t_List *List)
{
	t_element	*tmp;

	if (!List || !List->top)
		return ;
	tmp = List->top;
	while (tmp)
		tmp = tmp->next;
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

int	main(int argc, char **argv)
{
	t_List		*a;
	t_List		*b;
	//int			x;

	if (argc > 1)
	{
		if (!error_check(argv))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		b = (t_List *)malloc(sizeof(t_List));
		a = input_to_list(argv);
		if (!b || !a || !a->top || !a->top->next)
			return (0);
		//scanf("%d", &x);
		if (ft_lstsize(a) <= 3)
		{
			small_sort(a);
			return (0);
		}
		a->array = create_array(a);
		sort_array(a->array);
		a->size = ft_lstsize(a);
		b->top = NULL;
		//printf("THREE ? : %d", is_three_last(a, x));
		move_all_necessary(a, b, 'b');
		go_to_min(b, 'b');
		ft_three_sort(a);
		finish_move(a, b);
		free(a);
		free(b);
	}
	return (0);
}
