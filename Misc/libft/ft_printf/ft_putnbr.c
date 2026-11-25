/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 19:02:25 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/25 05:02:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count = count + ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		count = count + ft_putnbr(n / 10);
	}
	c = n % 10 + '0';
	count = count + ft_putchar(c);
	return (count);
}
