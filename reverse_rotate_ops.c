#include "push_swap.h"
#include "ft_printf.h"

void reverse_rotate(t_list *stack)
{
	t_node *last;

	if (stack->size < 2)
		return ;

	last = stack->tail;
	stack->tail = last->prev;
	stack->tail->next = NULL;

	last->next = stack->head;
	stack->head->prev = last;
	last->prev = NULL;
	stack->head = last;
}

void rra(t_list *stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void rrb(t_list *stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void rrr(t_list *stack_a, t_list *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
