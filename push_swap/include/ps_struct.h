/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharbon <dcharbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 22:58:11 by lragot            #+#    #+#             */
/*   Updated: 2026/11/26 22:17:29 by dcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRUCT_H
# define PS_STRUCT_H

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

typedef enum e_flag
{
	FLAG_NONE,
	FLAG_SIMPLE,
	FLAG_MEDIUM,
	FLAG_COMPLEX,
	FLAG_ADAPTIVE,
	FLAG_BENCH
}	t_flag;

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
	int		write;
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

#endif
