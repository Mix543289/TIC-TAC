/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 21:53:01 by lragot            #+#    #+#             */
/*   Updated: 2026/11/25 05:28:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

float dispatcher(t_stack a)
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