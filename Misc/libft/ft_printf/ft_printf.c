/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharbon <dcharbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 18:55:31 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/08 18:55:31 by dcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(const char *input_str, ...)
{
	va_list	args;
	int		i;
	int		total_count;

	if (!input_str)
		return (-1);
	va_start(args, input_str);
	i = 0;
	total_count = 0;
	while (input_str[i])
	{
		if (input_str[i] == '%')
		{
			i++;
			total_count = total_count + ft_dispatcher(input_str[i], args);
		}
		else
		{
			write(1, &input_str[i], 1);
			total_count++;
		}
		i++;
	}
	va_end(args);
	return (total_count);
}
