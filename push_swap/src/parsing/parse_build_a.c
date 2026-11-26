/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_build_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharbon <dcharbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 00:13:49 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/27 00:26:16 by dcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	parse_token_to_stack(t_app *app, const char *start, size_t len)
{
	int	value;

	if (!parse_int(start, len, &value))
		return (0);
	if (parse_search_multiple(&app->a, value))
		return (0);
	if (!stack_append_value(&app->a, value))
		return (0);
	return (1);
}