/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:20:04 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/03/25 09:20:05 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(char *s)
{
	int	i;

	i = 0;
	if (*s == '-')
		i++;
	if (s[i] == 0)
		return (0);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	error_check(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		if (ft_atoi(s[i]) > INT_MAX)
			return (0);
		if (ft_atoi(s[i]) < INT_MIN)
			return (0);
		j = i + 1;
		while (s[j])
		{
			if (ft_atoi(s[i]) == ft_atoi(s[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
