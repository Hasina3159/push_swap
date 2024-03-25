#include "checker.h"

void	char_to_move(t_List *List_a, t_List *List_b, char *s)
{
	if (ft_strcmp(s, "sa\n"))
		sa(List_a);
	else if (ft_strcmp(s, "sb\n"))
		sb(List_b);
	else if (ft_strcmp(s, "ss\n"))
		ss(List_a, List_b);
	else if (ft_strcmp(s, "pa\n"))
		pa(List_b, List_a);
	else if (ft_strcmp(s, "pb\n"))
		pb(List_a, List_b);
	else if (ft_strcmp(s, "ra\n"))
		ra(List_a);
	else if (ft_strcmp(s, "rb\n"))
		rb(List_b);
	else if (ft_strcmp(s, "rr\n"))
		rr(List_a, List_b);
	else if (ft_strcmp(s, "rra\n"))
		rra(List_a);
	else if (ft_strcmp(s, "rrb\n"))
		rrb(List_b);
	else if (ft_strcmp(s, "rrr\n"))
		rrr(List_a, List_b);
}

int	ft_loop(t_List *a, t_List *b, char *s)
{
	while (s)
	{
		if (!is_valid(s))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		char_to_move(a, b, s);
		s = get_next_line(0);
	}
	if (ft_lstsize(b) != 0 || !is_sorted(a))
	{
		write(1, "KO\n", 4);
		return (0);
	}
	write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_List		*a;
	t_List		*b;
	char		*s;
	char		**av;

	if (argc > 1)
	{
		av = argv;
		if (argc == 2)
			av = ft_split(argv[1], ' ');
		if (!error_check(argv))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		b = (t_List *)malloc(sizeof(t_List));
		if (!b)
			return (0);
		a = input_to_list(argv);
		s = get_next_line(0);
        return (ft_loop(a, b, s));
	}
	return (0);
}
