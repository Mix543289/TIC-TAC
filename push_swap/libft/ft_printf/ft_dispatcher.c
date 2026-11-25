/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 18:56:13 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/25 05:03:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_dispatcher(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count = count + ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		count = count + ft_putptr(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		count = count + ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		count = count + ft_putunbr(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count = count + ft_puthex(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		count = count + ft_putchar('%');
	return (count);
}
