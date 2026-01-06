#include "push_swap.h"
#include "ft_printf.h"


static void push_helper(t_list *source, t_list *destination)
{
	t_node *node_to_move;

	if (source->size == 0)
		return ;

	node_to_move = source->head;

	source->head = node_to_move->next;
	if (source->head != NULL)
		source->head->prev = NULL;
	else
		source->tail = NULL;
	source->size--;

	node_to_move->next = destination->head;
	if (destination->head != NULL)
		destination->head->prev = node_to_move;
	else
		destination->tail = node_to_move;

	destination->head = node_to_move;
	node_to_move->prev = NULL;
	destination->size++;
}

void pa(t_list *stack_a, t_list *stack_b)
{
	push_helper(stack_b, stack_a);
	ft_printf("pa\n");
}

void pb(t_list *stack_a, t_list *stack_b)
{
	push_helper(stack_a, stack_b);
	ft_printf("pb\n");
}
