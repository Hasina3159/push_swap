#include "push_swap.h"

void	show_det(t_List *List)
{
	t_element	*tmp;

	if (!List || !List->top)
		return ;
	tmp = List->top;
	while (tmp)
	{
		printf("[%d]\t-->\t%d\n", tmp->value, tmp->chunk);
		tmp = tmp->next;
	}
}

void	show_values(t_List *List)
{
	t_element	*tmp;

	if (!List || !List->top)
		return ;
	tmp = List->top;
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
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
		
		//move_all_necessary(a, b, 'b');
		//go_to_min(b, 'b');
		//ft_three_sort(a);
		//move_all(a, b, 'a');
		//array = create_array(a);
		//sort_array(array);
		//show_array(array);

		//pivots = get_all_pivot(array);
		init_chunks_and_pivots(a);


		//got_to_chunk_target(b, a, 1);
		//ra(a);

		ft_lst_pre_sort(a, b);
		//move_all_necessary(b, a);
		//show_det(b);
		show_values(b);
		free(a);
		free(b);
	}
	return (0);
}
