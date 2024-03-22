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
	//int			*array;
	//int			*pivots;

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
		b->top = NULL;
		move_all_necessary(a, b, 'b');
		go_to_min(b, 'b');
		finish_move(a, b);
		free(a);
		free(b);
	}
	return (0);
}
