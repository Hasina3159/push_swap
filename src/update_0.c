#include "push_swap.h"

void	init_chunks_and_pivots(t_List *List)
{
	t_element	*tmp;
	int			*array;
	int			*pivots;
	int			i;

	tmp = List->top;
	array = create_array(List);
	sort_array(array);
	pivots = get_all_pivot(array);
	if (!tmp || !array || !pivots)
		return ;
	List->pivots = pivots;
	List->sorted = array;
	while (tmp)
	{
		i = 1;
		while (i < 7)
		{
			if (tmp->value >= pivots[i] && tmp->value < pivots[i + 1])
				tmp->chunk = i;
			i++;
		}
		//printf("value : %d, chunk : %d\n", tmp->value, tmp->chunk);
		//show_values(List);
		tmp = tmp->next;
	}
}