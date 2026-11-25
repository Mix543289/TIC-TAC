/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:00:02 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/25 05:04:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_putnbr_to_str(long n, char *temp, int *i)
{
	if (n < 0)
	{
		temp[*i] = ('-');
		(*i)++;
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_to_str(n / 10, temp, i);
	}
	temp[*i] = n % 10 + '0';
	(*i)++;
	return (temp);
}

char	*ft_itoa(int n)
{
	char	*result;
	char	temp[12];
	char	*swap;
	int		len;
	int		i;

	i = 0;
	swap = ft_putnbr_to_str(n, temp, &i);
	swap[i] = '\0';
	len = (ft_strlen(swap)) + 1;
	result = malloc(len * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, swap, len);
	return (result);
}
