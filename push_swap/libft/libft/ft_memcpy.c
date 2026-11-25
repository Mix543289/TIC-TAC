/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 10:24:47 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/25 05:05:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*jsrc;
	unsigned char	*kdest;

	i = 0;
	jsrc = (unsigned char *)src;
	kdest = (unsigned char *)dest;
	while (i < n)
	{
		kdest[i] = jsrc[i];
		i++;
	}
	return (kdest);
}
