/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 18:18:15 by marvin            #+#    #+#             */
/*   Updated: 2026/11/25 18:18:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void rotate(t_stack *stack)
{
    t_node *node;
    node = stack->head;

    stack->head = node->next;
    node->next->prev = NULL;
    stack->tail->next = node; 
    node->prev = stack->tail;
    node->next = NULL; 
    stack->tail = node;
    return ; 
}
void ra(t_stack *a,t_stats *stats)
{
    if (!a || !a->head || !a->head->next)
        return ;
    rotate(a);
    if (!stats)
        return ;
    if (stats->write == 0)
        write(1, "ra\n", 3);
    stats->counts[5]++;
    stats->total++;
    return ;
}

void rb(t_stack *b,t_stats *stats)
{
    if (!b || !b->head || !b->head->next)
        return ;
    rotate(b);
    if (!stats)
        return ;
    if (stats->write == 0)
        write(1, "rb\n", 3);
    stats->counts[6]++;
    stats->total++;
    return ;
}
void rr(t_stack *a, t_stack *b,t_stats *stats)
{
    if (a && a->head && a->head->next)
        rotate(a);
    if (b && b->head && b->head->next)
        rotate(b);
    if (!stats)
        return ;
    if (stats->write == 0)
        write(1, "rr\n", 3);
    stats->counts[7]++;
    stats->total++;
    return ;
}