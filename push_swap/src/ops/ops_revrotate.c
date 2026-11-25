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
void rra(t_stack *a)
{
    if (!a || !a->tail || !a->tail->prev)
        return ;
    revrotate(a);
    return ;
}
void rrb(t_stack *b)
{
    if (!b || !b->tail || !b->tail->prev)
        return ;
    revrotate(b);
    return ;
}
void rrr(t_stack *a, t_stack *b)
{
    if (a && a->tail && a->tail->prev)
        revrotate(a);
    if (b && b->tail && b->tail->prev)
        revrotate(b);
    return ;
}