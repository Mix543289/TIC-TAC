/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 17:48:38 by marvin            #+#    #+#             */
/*   Updated: 2026/11/25 17:48:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"


static void rompt(t_stack *x, t_node *y)
{
    if (y->next)
    {
        x->head = y->next;
        x->head->prev = NULL;
    }
    else
    {
        x->head = NULL;
        x->tail = NULL;
    }
    return ;
}

static void fill(t_stack *x, t_node *y)
{
    if (!x->head)
        x->tail = y;
    else
        x->head->prev = y;
    y->prev = NULL;
    y->next = x->head;
    x->head = y;
    return ;
}
static void	check(t_stack *dst, t_stack *src)
{
	t_node	*node;

	if (!dst || !src || !src->head)
		return ;
	node = src->head;
	rompt(src, node);
	node->next = NULL;
	node->prev = NULL;
	fill(dst, node);
	src->size--;
	dst->size++;
    return ;
}

void    pa(t_stack *a, t_stack *b, t_stats *stats)
{
    check(a, b);
    if (!stats)
        return ;
    if (stats->write == 0)
        write(1, "pa\n", 3);
    bench_add(stats, 3);
    return ;
}
void	pb(t_stack *a, t_stack *b, t_stats *stats)
{
    check(b, a);
    if (!stats)
        return ;
    if (stats->write == 0)
        write(1, "pb\n", 3);
    bench_add(stats, 4);
    return ;
}
