/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharbon <dcharbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 01:25:35 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/25 23:56:16 by dcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "ps_struct.h"
# include "ps_sort.h"
# include "ps_ops.h"

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

typedef enum e_mode
{
	MODE_ADAPTIVE,
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX
}	t_mode;

typedef struct s_options
{
	t_mode	mode;
	int		bench;
}	t_options;

typedef struct s_stats
{
	long	counts[11];
	long	total;
	double	disorder;
	t_mode	used_mode;
}	t_stats;

typedef struct s_app
{
	t_stack		a;
	t_stack		b;
	t_options	options;
	t_stats		stats;
	int			initial_size;
}	t_app;

int		parse_arguments(t_app *app, int argc, char **argv);
#endif

