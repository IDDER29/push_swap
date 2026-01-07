/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idait-el <idait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:00:00 by idait-el          #+#    #+#             */
/*   Updated: 2026/01/06 22:48:25 by idait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void set_move_strategy(t_node *node, int src_fwd, int dest_fwd,
							  int src_rev, int dest_rev)
{
	int costs[4];

	costs[0] = ft_max(src_fwd, dest_fwd);
	costs[1] = ft_max(src_rev, dest_rev);
	costs[2] = src_fwd + dest_rev;
	costs[3] = src_rev + dest_fwd;
	node->cost = ft_min(ft_min(costs[0], costs[1]), ft_min(costs[2], costs[3]));
	init_move_counts(node);
	if (node->cost == costs[0])
		set_rr_moves(node, src_fwd, dest_fwd);
	else if (node->cost == costs[1])
		set_rrr_moves(node, src_rev, dest_rev);
	else if (node->cost == costs[2])
	{
		node->ra_count = src_fwd;
		node->rrb_count = dest_rev;
	}
	else
	{
		node->rra_count = src_rev;
		node->rb_count = dest_fwd;
	}
}

/*
 * calculate_cost: compute min rotation cost for nodes in source to targets in dest.
 */
void calculate_cost(t_list *source, t_list *destination)
{
	t_node *node;
	int src_fwd;
	int dest_fwd;
	int src_rev;
	int dest_rev;

	if (destination->size == 0)
		return;
	node = source->head;
	while (node != NULL)
	{
		get_distances(node, source, destination, &src_fwd, &dest_fwd, &src_rev, &dest_rev);
		set_move_strategy(node, src_fwd, dest_fwd, src_rev, dest_rev);
		node = node->next;
	}
}
