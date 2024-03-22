#include "push_swap.h"

int *create_array(t_List *List)
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
			//printf("array_i[%d] : %d, array_j[%d] : %d\n", i, array[i], j, array[j]);
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				//printf("\nato\n");
			}
			j++;
		}
		i++;
	}
}

int	*push_array(int *array, int n)
{
	int	size;
	int	*new;
	int	i;

	size = array[0];
	new = (int *)malloc(sizeof(int) * (size + 1));
	if (new == NULL)
		return (NULL);
	new[0] = size + 1;
	i = 1;
	while (i < size + 1)
	{
		new[i] = array[i];
		i++;
	}
	new[i] = n;
		return (new);
}

void	show_array(int *array)
{
	int	i;

	i = 1;
	while (i < array[0])
	{
		//printf("[%d] ", array[i]);
		i++;
	}
}

int *get_all_pivot(int *array)
{
	int	*pivots;
	int	pivot;
	int	size;
	int	n;
	int	i;

	size = array[0];
	n = size / 6;
	if (size < 10)
		return (NULL);
	pivots = (int *)malloc(sizeof(int) * 8);
	if (pivots == NULL)
		return (NULL);
	pivots[0] = 8;
	pivots[1] = 0;
	pivot = 0;
	i = 2;
	while (i < 7)
	{
		pivot = pivot + n;
		pivots[i] = array[pivot];
		//printf("[%d] size : %d, n : %d, pivot : %d, n : %d, array_p : %d\n", i, size, n, pivot, pivots[i], array[pivot]);
		i++;
	}
	pivots[7] = array[size - 1] + 1;
		//printf("[%d] size : %d, n : %d, pivot : %d, n : %d, array_p : %d\n", i, size, n, pivot, pivots[i], array[pivot]);
	return (pivots);
}

