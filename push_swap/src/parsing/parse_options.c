/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharbon <dcharbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 07:01:31 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/26 07:31:10 by dcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_flag	parse_flag_kind(const char *arg)
{
	if (parse_same(arg, "--simple"))
		return (FLAG_SIMPLE);
	if (parse_same(arg, "--medium"))
		return (FLAG_MEDIUM);
	if (parse_same(arg, "--complex"))
		return (FLAG_COMPLEX);
	if (parse_same(arg, "--adaptive"))
		return (FLAG_ADAPTIVE);
	if (parse_same(arg, "--bench"))
		return (FLAG_BENCH);
	return (FLAG_NONE);
}

static int	parse_set_mode(t_app *app, t_flag flag, int *seen)
{
	if (*seen)
		return (0);
	if (flag == FLAG_SIMPLE)
		app->options.mode = MODE_SIMPLE;
	else if (flag == FLAG_MEDIUM)
		app->options.mode = MODE_MEDIUM;
	else if (flag == FLAG_COMPLEX)
		app->options.mode = MODE_COMPLEX;
	else if (flag == FLAG_ADAPTIVE)
		app->options.mode = MODE_ADAPTIVE;
	else
		return (0);
	*seen = 1;
	return (1);
}

int	parse_options(t_app *app, int argc, char **argv)
{
	int		i;
	int		seen_mode;
	t_flag	flag;

	i = 1;
	seen_mode = 0;
	while (i < argc)
	{
		flag = parse_flag_kind(argv[i]);
		if (flag == FLAG_BENCH && app->options.bench)
			return (0);
		if (flag == FLAG_BENCH)
			app->options.bench = 1;
		else if (flag != FLAG_NONE
			&& !parse_set_mode(app, flag, &seen_mode))
			return (0);
		if (flag == FLAG_NONE && argv[i][0] == '-'
			&& argv[i][1] == '-')
			return (0);
		i++;
	}
	return (1);
}
