/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 16:55:33 by marvin            #+#    #+#             */
/*   Updated: 2026/11/25 16:55:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void swap(t_stack *x)
{
    t_node	*first;
    t_node	*second;
    t_node	*third;
    first = x->head;
    second = first->next;
    third = NULL;
    if (second->next)
    {
        third = second->next;
        third->prev = first;
    }
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    first->next = third;
    x->head = second;
}

void	sa(t_stack *a)
{
    if (!a || !a->head || !a->head->next)
        return ;
    swap(a);
    return ;   
}
void	sb(t_stack *b)
{
    if (!b || !b->head || !b->head->next)
        return ;
    swap(b);
    return ;   
}
void	ss(t_stack *a, t_stack *b)
{
    if (a && a->head && a->head->next)
        swap(a);
    if (b && b->head && b->head->next)
        swap(b);
    return ;
}