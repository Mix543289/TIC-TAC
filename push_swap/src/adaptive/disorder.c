/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lragot <lragot@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 21:52:01 by lragot            #+#    #+#             */
/*   Updated: 2026/11/24 21:52:43 by lragot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "ps_ops.h"
#include "ps_sort.h"

float compute_disorder(stack a)
{
    int mistakes = 0;
    int total_pairs = 0;
    int i;
    int j;
    int size;
    i =0;
    size = count(a)-1;
    while (i < size)
    {
        j = i+1;
        while (j<size)
        {
            total_pairs += 1;
        }
        if (a[i] > a[j])
            mistakes += 1;        
    }
    return(mistakes/total_pairs);
}