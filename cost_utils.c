/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idait-el <idait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 00:00:00 by idait-el          #+#    #+#             */
/*   Updated: 2026/01/07 00:00:00 by idait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_rr_moves(t_node *node, int src_fwd, int dest_fwd)
{
    node->rr_count = ft_min(src_fwd, dest_fwd);
    node->ra_count = src_fwd - node->rr_count;
    node->rb_count = dest_fwd - node->rr_count;
}

void set_rrr_moves(t_node *node, int src_rev, int dest_rev)
{
    node->rrr_count = ft_min(src_rev, dest_rev);
    node->rra_count = src_rev - node->rrr_count;
    node->rrb_count = dest_rev - node->rrr_count;
}
