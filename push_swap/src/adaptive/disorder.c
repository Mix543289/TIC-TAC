/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 21:52:01 by lragot            #+#    #+#             */
/*   Updated: 2026/11/25 05:28:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/push_swap.h"

float compute_disorder(t_stack a)
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