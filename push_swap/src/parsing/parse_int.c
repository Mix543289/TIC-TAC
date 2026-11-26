/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharbon <dcharbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 01:40:02 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/27 00:40:10 by dcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	parse_limits(long long *result, int digit, int sign)
{
	long long	limit;

	limit = INT_MAX;
	if (sign == -1)
		limit = -(long long)INT_MIN;
	if (*result > (limit - digit) / 10)
		return (0);
	*result = *result * 10 + digit;
	return (1);
}

int	parse_int(const char *str, size_t len, int *out)
{
	size_t		i;
	long long	result;
	int			sign;

	result = 0;
	i = 0;
	sign = 1;
	if (!str || !out || len == 0)
		return (0);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (i == len)
		return (0);
	while (i < len)
	{
		if ((str[i] < '0' || str[i] > '9')
			|| (!parse_limits(&result, str[i] - '0', sign)))
			return (0);
		i++;
	}
	*out = (int)(result * sign);
	return (1);
}

// Check et accumule un chiffre sans depasser les limites d'un int.
// Convert une chaine de longueur len en int et retourne 1 si valide, 0 sinon.