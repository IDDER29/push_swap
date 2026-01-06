/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idait-el <idait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:00:00 by idait-el          #+#    #+#             */
/*   Updated: 2026/01/06 16:54:47 by idait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * sort_three: sort exactly three elements in the given stack using the
 * minimal sequence of operations (sa, ra, rra). This function assumes
 * the stack contains exactly three nodes.
 */
void sort_three(t_list *stack)
{
    if (stack->size != 3)
        return;

    int a = stack->head->data;
    int b = stack->head->next->data;
    int c = stack->tail->data;

    if (a > b && b < c && a < c)
        sa(stack);
    else if (a > b && b > c)
    {
        sa(stack);
        rra(stack);
    }
    else if (a > b && b < c && a > c)
        ra(stack);
    else if (a < b && b > c && a < c)
    {
        sa(stack);
        ra(stack);
    }
    else if (a < b && b > c && a > c)
        rra(stack);
}

/*
 * push_to_destination: move elements from `source` to `destination`
 * until only three elements remain in `source`.
 */
void push_to_destination(t_list *source, t_list *destination)
{
    if (source->size <= 3)
        return;

    while (source->size > 3)
        pb(source, destination);
}
