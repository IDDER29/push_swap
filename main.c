#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"

void execute_moves(t_list *stack_a, t_list *stack_b, t_node *node)
{
	int i;

	i = 0;
	while (i++ < node->rr_count)
		rr(stack_a, stack_b);
	i = 0;
	while (i++ < node->rrr_count)
		rrr(stack_a, stack_b);
	i = 0;
	while (i++ < node->ra_count)
		ra(stack_a);
	i = 0;
	while (i++ < node->rb_count)
		rb(stack_b);
	i = 0;
	while (i++ < node->rra_count)
		rra(stack_a);
	i = 0;
	while (i++ < node->rrb_count)
		rrb(stack_b);
	pa(stack_a, stack_b);
}

t_node *find_min_cost(t_list *stack)
{
	t_node *current;
	t_node *min_node;

	if (!stack || !stack->head)
		return (NULL);
	min_node = stack->head;
	current = stack->head->next;
	while (current)
	{
		if (current->cost < min_node->cost)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}
int main(void)
{
	int a[] = {12, 67, 3, 0, -5, 99, 8, 23, -1, 42};
	int size_a;
	int i;
	t_list stack_a;
	t_list stack_b;

	size_a = sizeof(a) / sizeof(a[0]);
	i = 0;

	stack_init(&stack_a);
	stack_init(&stack_b);

	while (i < size_a)
	{
		if (create_node(&stack_a, a[i]) == -1)
		{
			ft_printf("Error: Memory allocation failed\n");
			stack_free(&stack_a);
			stack_free(&stack_b);
			return (-1);
		}
		i++;
	}

	ft_printf("Initial stack_a:\n");
	print_stack(&stack_a);

	push_to_destination(&stack_a, &stack_b);

	ft_printf("-------------------------------------------------------\n");

	ft_printf("after step 1 \nSTACK A :\n");

	print_stack(&stack_a);
	ft_printf("STACK B :\n");
	print_stack(&stack_b);

	ft_printf("-------------------------------------------------------\n");

	ft_printf("STACK A :\n");

	sort_three(&stack_a);
	print_stack(&stack_a);

	ft_printf("STACK B :\n");
	print_stack(&stack_b);

	assign_indices(&stack_a);
	assign_indices(&stack_b);

	ft_printf("STACK A :\n");
	print_stack(&stack_a);
	ft_printf("STACK B :\n");
	print_stack(&stack_b);

	assign_targets(&stack_b, &stack_a);

	ft_printf("STACK A :\n");
	print_stack(&stack_a);
	ft_printf("STACK B :\n");
	print_stack(&stack_b);

	calculate_cost(&stack_b, &stack_a);

	ft_printf("STACK A :\n");
	print_stack(&stack_a);
	ft_printf("STACK B :\n");
	print_stack(&stack_b);

	t_node *cheapest;
	t_node *min_node;

	while (stack_b.size > 0)
	{
		assign_indices(&stack_a);
		assign_indices(&stack_b);
		assign_targets(&stack_b, &stack_a);
		calculate_cost(&stack_b, &stack_a);
		cheapest = find_min_cost(&stack_b);
		execute_moves(&stack_a, &stack_b, cheapest);
	}
	assign_indices(&stack_a);
	min_node = find_index_zero_node(&stack_a);
	if (min_node)
	{
		if (min_node->index <= stack_a.size / 2)
			while (stack_a.head != min_node)
				ra(&stack_a);
		else
			while (stack_a.head != min_node)
				rra(&stack_a);
	}
	ft_printf("\nFinal sorted stack_a:\n");
	print_stack(&stack_a);

	stack_free(&stack_a);
	stack_free(&stack_b);
	return (0);
}
