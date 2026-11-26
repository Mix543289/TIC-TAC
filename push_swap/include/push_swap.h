/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharbon <dcharbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 01:25:35 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/26 22:57:51 by dcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "ps_struct.h"
# include "ps_sort.h"
# include "ps_ops.h"

void		bench_add(t_stats *stats, int operation);

int			parse_int(const char *str, size_t len, int *out);
int			parse_options(t_app *app, int argc, char **argv);
int			parse_search_multiple(const t_stack *stack, int value);
#endif
