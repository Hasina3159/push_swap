/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:42:10 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/03/25 15:33:36 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t	i;
	char	*mem;
	size_t	len;

	len = n * size;
	mem = (char *)malloc(len);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)mem);
}
