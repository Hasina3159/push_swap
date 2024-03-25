#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
#include <limits.h>
# include <stdio.h>

typedef struct s_element
{
	int					value;
	struct s_element	*next;
}						t_element;

typedef struct s_List
{
	t_element	*top;
}				t_List;

void		*ft_calloc(size_t n, size_t size);
char		**ft_split(char const *s, char c);
int			error_check(char **s);
int			is_sorted(t_List *List);
void		ft_putstr(char *s);
long		ft_atoi(const char *str);
void		free_all(t_List *List);
t_List		*input_to_list(char **argv);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
int			is_valid(char *s);
void		sa(t_List *List_a);
void		sb(t_List *List_b);
void		ss(t_List *List_a, t_List *List_b);
void		pa(t_List *List_b, t_List *List_a);
void		pb(t_List *List_a, t_List *List_b);
void		ra(t_List *List_a);
void		rb(t_List *List_b);
void		rr(t_List *List_a, t_List *List_b);
void		rra(t_List *List_a);
void		rrb(t_List *List_b);
void		rrr(t_List *List_a, t_List *List_b);
int			ft_strcmp(char *s1, char *s2);
int			ft_lstsize(t_List *List);

#endif
