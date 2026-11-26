/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharbon <dcharbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 07:01:31 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/27 00:34:18 by dcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	parse_same(const char *a, const char *b)
{
	if (ft_strncmp(a, b, ft_strlen(b) + 1) == 0)
		return (1);
	return (0);
}

t_flag	parse_flag_type(const char *arg)
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

static int	parse_set_mode(t_app *app, t_flag flag, int *checked)
{
	if (*checked)
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
	*checked = 1;
	return (1);
}

int	parse_options(t_app *app, int argc, char **argv)
{
	int		i;
	int		checked;
	t_flag	flag;

	i = 1;
	checked = 0;
	while (i < argc)
	{
		flag = parse_flag_type(argv[i]);
		if (flag == FLAG_BENCH && app->options.bench)
			return (0);
		if (flag == FLAG_BENCH)
			app->options.bench = 1;
		else if (flag != FLAG_NONE
			&& !parse_set_mode(app, flag, &checked))
			return (0);
		if (flag == FLAG_NONE && argv[i][0] == '-'
			&& argv[i][1] == '-')
			return (0);
		i++;
	}
	return (1);
}

// Compare (strcmp) deux chaines et retourne 1 si identiques, 0 sinon.
// ID une option par comparaison et retourne son flag, ou FLAG_NONE si inconnue.
// save le mode de tri et refuse plusieurs modes via flag de check.
// Lecture des arguments, save les options et refuse les flags invalides.