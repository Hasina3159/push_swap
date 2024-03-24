#include "push_swap.h"

int	*create_array(t_List *List)
{
	int			size;
	int			*array;
	int			i;
	t_element	*tmp;

	size = ft_lstsize(List);
	if (size <= 0)
		return (NULL);
	array = (int *)malloc(sizeof(int) * (size + 1));
	if (array == NULL)
		return (NULL);
	i = 1;
	tmp = List->top;
	array[0] = size + 1;
	List->size = size;
	while (tmp)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (array);
}

void	sort_array(int *array)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < array[0] - 1)
	{
		j = i + 1;
		while (j < array[0])
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
