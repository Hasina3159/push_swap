#include "push_swap.h"

t_element    *ft_lstnew(int value)
{
	t_element   *new;

	new = (t_element *)malloc(sizeof(t_element));
	if (new == NULL)
		return (NULL);

	new->value = value;
	new->next = NULL;
	return (new);
}

void	push_to_end(t_List *List, char *s)
{
	t_element	*new;
	t_element	*tmp;

	new = ft_lstnew(ft_atoi(s));
	if (new == NULL || List == NULL)
		return ;
	tmp = List->top;
	if (tmp == NULL)
	{
		List->top = new;
		return ;
	}

	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_List   *input_to_list(char **argv)
{
	t_List		*final;
	t_element	*tmp;
	int			i;

	if (!argv || !*argv)
		return (NULL);
	final = (t_List *)malloc(sizeof(t_List));
	if (final == NULL)
		return (NULL);
	final->top = NULL;
	i = 1;
	while (argv[i])
	{
		push_to_end(final, argv[i]);
		i++;
	}
	
	return (final);
}