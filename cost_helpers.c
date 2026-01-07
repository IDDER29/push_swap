/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idait-el <idait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 00:00:00 by idait-el          #+#    #+#             */
/*   Updated: 2026/01/07 00:00:00 by idait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_distances(t_node *node, t_list *src, t_list *dest,
                   int *src_fwd, int *dest_fwd, int *src_rev, int *dest_rev)
{
    *src_fwd = node->index;
    *dest_fwd = node->target;
    *src_rev = src->size - *src_fwd;
    *dest_rev = dest->size - *dest_fwd;
}

int ft_min(int a, int b)
{
    if (a < b)
        return (a);
    return (b);
}

int ft_max(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

void init_move_counts(t_node *node)
{
    node->rr_count = 0;
    node->rrr_count = 0;
    node->ra_count = 0;
    node->rra_count = 0;
    node->rb_count = 0;
    node->rrb_count = 0;
}
