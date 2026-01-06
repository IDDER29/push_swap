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
#define MAX_COST 99999

static void get_distances(t_node *node, t_list *src, t_list *dest,
							int *src_fwd, int *dest_fwd, int *src_rev, int *dest_rev)
{
	*src_fwd = node->index % src->size;
	*dest_fwd = node->target % dest->size;
	*src_rev = src->size - *src_fwd;
	*dest_rev = dest->size - *dest_fwd;
}

static int get_min_cost(t_node *node, t_list *source, t_list *destination,
						int src_fwd, int dest_fwd, int src_rev, int dest_rev)
{
	int rr_cost;
	int rrr_cost;
	int mixed_cost;
	int min_cost;

    rr_cost = dest_fwd;
	rrr_cost = dest_rev;
	if (src_fwd > dest_fwd)
		rr_cost = src_fwd;
	if (src_rev > dest_rev)
		rrr_cost = src_rev;
	if (node->index < source->size / 2 && node->target > destination->size / 2)
		mixed_cost = src_fwd + dest_rev;
	else if (node->index > source->size / 2 && node->target < destination->size / 2)
		mixed_cost = src_rev + dest_fwd;
	else
		mixed_cost = MAX_COST;
	if (rr_cost < rrr_cost && rr_cost < mixed_cost)
		min_cost = rr_cost;
	else if (rrr_cost < mixed_cost)
		min_cost = rrr_cost;
	else
		min_cost = mixed_cost;
	return min_cost;
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
		node->cost = get_min_cost(node, source, destination, src_fwd, dest_fwd, src_rev, dest_rev);
		node = node->next;
	}
}
