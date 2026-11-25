/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 10:40:20 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/25 05:05:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*jsrc;
	unsigned char	*kdest;

	jsrc = (unsigned char *)src;
	kdest = (unsigned char *)dest;
	if (jsrc == kdest || n == 0)
		return (kdest);
	if (kdest < jsrc)
	{
		i = 0;
		while (i < n)
		{
			kdest[i] = jsrc[i];
			i++;
		}
	}
	else if (jsrc < kdest)
	{
		while (n--)
		{
			kdest[n] = jsrc[n];
		}
	}
	return (kdest);
}
