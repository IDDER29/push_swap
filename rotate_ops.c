#include "push_swap.h"
#include "ft_printf.h"

void rotate(t_list *stack)
{
	t_node *first;
	ft_printf("ra\n");
	if (stack->size < 2)
		return ;

	first = stack->head;
	stack->head = first->next;
	ft_printf("rb\n");

	stack->tail->next = first;
	first->prev = stack->tail;
	first->next = NULL;
	stack->tail = first;
}

void ra(t_list *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void rb(t_list *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void rr(t_list *stack_a, t_list *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
