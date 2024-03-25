#include "checker.h"

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
