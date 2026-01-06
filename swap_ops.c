#include "push_swap.h"
#include "ft_printf.h"

void swap_top_two(t_list *stack)
{
	t_node *first;
	t_node *second;

	if (stack->size < 2)
		return ;

	first = stack->head;
	second = first->next;

	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	stack->head = second;
	if (stack->size == 2)
		stack->tail = first;
}

void sa(t_list *stack_a)
{
	swap_top_two(stack_a);
	ft_printf("sa\n");
}

void sb(t_list *stack_b)
{
	swap_top_two(stack_b);
	ft_printf("sb\n");
}

void ss(t_list *stack_a, t_list *stack_b)
{
	swap_top_two(stack_a);
	swap_top_two(stack_b);
	ft_printf("ss\n");
}
