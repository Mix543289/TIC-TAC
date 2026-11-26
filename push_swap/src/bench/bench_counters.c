/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_counters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lragot <lragot@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 02:06:46 by lragot            #+#    #+#             */
/*   Updated: 2026/11/26 03:36:15 by lragot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void    bench_init(t_stats *stats)
{
    int i;

    i = 0;
    while (i < 11)
    {
        stats->counts[i] = 0;
        i++;
    }
    stats->total = 0;
    stats->disorder = 0.0;
}

void    bench_add(t_stats *stats, int operation)
{
    if (!stats || operation < 0 || operation >= 11)
        return ;
    stats->counts[operation]++;
    stats->total++;
}
