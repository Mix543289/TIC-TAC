/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharbon <dcharbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 23:53:10 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/27 00:26:14 by dcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	parse_arguments(t_app *app, int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (1);
	if (!parse_options(app, argc, argv))
		return (0);
	i = 1;
	while (i < argc)
	{
		if (parse_flag_type(argv[i]) == FLAG_NONE
			&& !parse_scan_arg(app, argv[i]))
			return (0);
		i++;
	}
	if (app->a.size == 0)
		return (0);
	app->initial_size = app->a.size;
	return (1);
}


