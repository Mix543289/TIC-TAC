/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharbon <dcharbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 01:25:35 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/26 07:04:55 by dcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "ps_struct.h"
# include "ps_sort.h"
# include "ps_ops.h"

int			parse_limits(long long *result, int digit, int sign);
int			parse_int(const char *str, size_t len, int *out);
static int	parse_set_mode(t_app *app, t_flag flag, int *seen);
t_flag		parse_flag_kind(const char *arg);
#endif
