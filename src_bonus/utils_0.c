/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:21:11 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/03/25 12:48:03 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	
	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_valid(char *s)
{
	if (ft_strcmp(s, "sa\n") || ft_strcmp(s, "sb\n") || ft_strcmp(s, "ss\n"))
		return (1);
	if (ft_strcmp(s, "pa\n") || ft_strcmp(s, "pb\n"))
		return (1);
	if (ft_strcmp(s, "ra\n") || ft_strcmp(s, "rb\n") || ft_strcmp(s, "rr\n"))
		return (1);
	if (ft_strcmp(s, "rra\n") || ft_strcmp(s, "rrb\n"))
		return (1);
	if (ft_strcmp(s, "rrr\n"))
		return (1);
	return (0);
}


long	ft_atoi(const char *str)
{
	int		i;
	long	r;
	int		s;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			r = r * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	return (s * r);
}

int	ft_lstsize(t_List *List)
{
	int			i;
	t_element	*tmp;

	i = 0;
	if (!List || !List->top)
		return (0);
	tmp = List->top;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
