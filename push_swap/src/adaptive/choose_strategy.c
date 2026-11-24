/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lragot <lragot@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 21:53:01 by lragot            #+#    #+#             */
/*   Updated: 2026/11/24 21:56:09 by lragot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "ps_ops.h"
#include "ps_sort.h"

float dispatcher(stack a)
{
    float percent;
    percent = compute_disorder(a);

    if (percent < 0.2 || NB(a) <= 5)
        simple;
    else if (percent >= 0.2 && percent < 0.5)
        medium;
    else if (percent >= 0.5)
        complex;  
    return(percent)
}