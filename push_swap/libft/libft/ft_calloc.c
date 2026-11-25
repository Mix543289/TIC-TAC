/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 16:59:48 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/25 05:04:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t			i;
	char			*result;

	i = 0;
	if (num != 0 && size > __SIZE_MAX__ / num)
		return (NULL);
	result = (char *)malloc(num * size);
	if (result == NULL)
		return (NULL);
	while (i < (num * size))
	{
		result[i] = 0;
		i++;
	}
	return (result);
}
