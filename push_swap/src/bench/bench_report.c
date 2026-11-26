/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_report.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lragot <lragot@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 02:19:50 by lragot            #+#    #+#             */
/*   Updated: 2026/11/26 04:44:49 by lragot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"


static void bench_print_strategy(t_mode mode)
{
    ft_putstr_fd("[bench] strategy: ", 2);
    if (mode == MODE_ADAPTIVE)
        ft_putstr_fd("Adaptive", 2);
    else if (mode == MODE_SIMPLE)
        ft_putstr_fd("Simple / O(n^2)", 2);
    else if (mode == MODE_MEDIUM)
        ft_putstr_fd("Medium / O(n*sqrt(n))", 2);
    else if (mode == MODE_COMPLEX)
        ft_putstr_fd("Complex / O(n log n)", 2);
    ft_putchar_fd('\n', 2);
}

void    bench_report(t_stats *stats)
{
    int disord;
    int decimal;

    disord = (int)(stats->disorder * 10000 + 0.5);
    decimal = disord % 100;

    ft_putstr_fd("[bench] disorder: ", 2);
    ft_putnbr_fd(disord / 100, 2);
    ft_putchar_fd('.', 2);
    if (decimal < 10)
        ft_putchar_fd('0', 2);
    ft_putnbr_fd(decimal, 2);
    ft_putstr_fd("%\n", 2);
}