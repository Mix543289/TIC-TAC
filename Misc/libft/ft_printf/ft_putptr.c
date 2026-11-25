/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 20:18:14 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/25 05:02:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
		count = count + ft_putstr("(nil)");
	else
	{
		count = count + ft_putstr("0x");
		count = count + ft_puthex((unsigned long)ptr, 'x');
	}
	return (count);
}
