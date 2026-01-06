/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idait-el <idait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:00:00 by idait-el          #+#    #+#             */
/*   Updated: 2026/01/06 21:19:38 by idait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

/*
 * find_index_zero_node: find the node with index 0 in the stack.
 * Assumes indices are assigned via assign_indices.
 */
t_node *find_index_zero_node(t_list *stack)
{
	if (stack->size == 0)
		return NULL;
	t_node *current_node = stack->head;
	while (current_node != NULL)
	{
		if (current_node->index == 0)
			return current_node;
		current_node = current_node->next;
	}
	return NULL;
}

/*
 * assign_targets: assign target indices to nodes in source stack
 * based on the best insertion point in destination stack.
 */
void assign_targets(t_list *source, t_list *destination)
{
	t_node *src, *dest, *target;

	if (source->size == 0)
		return;
	src = source->head;
	while (src != NULL)
	{
		dest = destination->head;
		target = NULL;
		while (dest != NULL)
		{
			if (src->data < dest->data &&
				(target == NULL || target->data > dest->data))
				target = dest;
			dest = dest->next;
		}
		if (target == NULL)
			target = find_index_zero_node(destination);
		src->target = target->index;
		src = src->next;
	}
}

/*
 * assign_indices: assign sequential indices (0 to size-1) to stack nodes.
 */
void assign_indices(t_list *stack)
{
	if (stack->size == 0)
		return;
	t_node *current = stack->head;
	int i = 0;
	while (current != NULL)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}