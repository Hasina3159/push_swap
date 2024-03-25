#include "checker.h"

void	free_list(t_element *top)
{ 
	if (top->next)
		free_list(top->next);
	if (top)
		free(top);
}

void	free_all(t_List *List)
{
	if (!List)
		return ;
	if (List->top)
		free_list(List->top);
	free(List);
}
