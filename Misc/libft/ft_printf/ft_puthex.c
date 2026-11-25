/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 19:10:12 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/25 05:03:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_puthex(unsigned long n, char specifier)
{
	char	*base;
	int		count;

	count = 0;
	if (specifier == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count = count + ft_puthex(n / 16, specifier);
	count = count + ft_putchar(base[n % 16]);
	return (count);
}
