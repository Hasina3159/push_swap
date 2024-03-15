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

int	main(int argc, char **argv)
{
	t_List		*a;
	t_List		*b;
	t_element	*tmp;

	if (argc > 1)
	{
		b = (t_List *)malloc(sizeof(t_List));
		a = input_to_list(argv);
		if (b == NULL || a == NULL)
			return (1);
		b->top = NULL;
		tmp = a->top;
		//show_values(a);
		//printf("\n");
		ft_lstsort(a, b);
		show_values(a);

	}
	return (0);
}
