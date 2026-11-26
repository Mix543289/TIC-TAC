/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharbon <dcharbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 22:59:34 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/27 00:26:19 by dcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	parse_is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	parse_next_token(const char *s, size_t *cursor,
		const char **start, size_t *len)
{
	size_t	i;

	i = *cursor;
	while (s[i] && parse_is_space(s[i]))
		i++;
	if (!s[i])
		return (*cursor = i, 0);
	*start = s + i;
	while (s[i] && !parse_is_space(s[i]))
		i++;
	*len = (size_t)(s + i - *start);
	*cursor = i;
	return (1);
}

int	parse_scan_arg(t_app *app, const char *arg)
{
	size_t		cursor;
	const char	*start;
	size_t		len;
	int			checked;

	if (!arg || !*arg)
		return (0);
	cursor = 0;
	checked = 0;
	while (parse_next_token(arg, &cursor, &start, &len))
	{
		checked = 1;
		if (!parse_token_to_stack(app, start, len))
			return (0);
	}
	return (checked);
}

// Check caracteres ignores.
// 1 : token found. 0 : no more tokens.
// Le token devient un int qui go a la FIN de la pile A.