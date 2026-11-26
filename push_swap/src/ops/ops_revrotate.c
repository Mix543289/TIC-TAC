/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_revrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 18:48:53 by marvin            #+#    #+#             */
/*   Updated: 2026/11/25 18:48:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void revrotate(t_stack *stack)
{
    t_node  *node;
    t_node  *node_head;

    node = stack->tail;
    node_head = stack->head;
    stack->tail = node->prev;
    stack->tail->next = NULL;
    node->prev = NULL;
    stack->head = node;
    node_head->prev = node;
    node->next = node_head;
    return ;
}
void rra(t_stack *a,t_stats *stats)
{
    if (!a || !a->tail || !a->tail->prev)
        return ;
    revrotate(a);
    if (!stats)
        return ;
    if (stats->write == 0)
        write(1, "rra\n", 4);
    stats->counts[8]++;
    stats->total++;
    return ;
}
void rrb(t_stack *b,t_stats *stats)
{
    if (!b || !b->tail || !b->tail->prev)
        return ;
    revrotate(b);
    if (!stats)
        return ;
    if (stats->write == 0)
        write(1, "rrb\n", 4);
    stats->counts[9]++;
    stats->total++;
    return ;
}
void rrr(t_stack *a, t_stack *b,t_stats *stats)
{
    if (a && a->tail && a->tail->prev)
        revrotate(a);
    if (b && b->tail && b->tail->prev)
        revrotate(b);
    if (!stats)
        return ;
    if (stats->write == 0)
        write(1, "rrr\n", 4);
    stats->counts[10]++;
    stats->total++;
    return ;
}