#include "push_swap.h"

void	show_values(t_List *List)
{
	t_element	*tmp;

	if (!List || !List->top)
		return ;
	tmp = List->top;
	while (tmp)
	{
		printf("[%d] ", tmp->value);
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
		//show_values(a);
		//printf("\n");
		ft_lstsort(a, b);
		ft_lstfree(a);
		free(a);
		free(b);
		//show_values(a);

	}
	return (0);
}
