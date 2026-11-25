/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharbon <dcharbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 21:54:27 by lragot            #+#    #+#             */
/*   Updated: 2026/11/25 01:30:08 by dcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PS_SORT_H
# define PS_SORT_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include "push_swap.h"

float dispatcher(stack a);
float compute_disorder(stack a);

#endif