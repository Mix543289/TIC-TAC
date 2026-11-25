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
}

void	pa(t_stack *a, t_stack *b)
{
    check(a, b);
}
void	pb(t_stack *a, t_stack *b)
{
    check(b, a);
}
