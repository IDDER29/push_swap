#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"

int main(void)
{
	int		a[] = {12, 67, 3, 0, -5, 99, 8, 23, -1, 42};
	int		size_a;
	int		i;
	t_list	stack_a;
	t_list	stack_b;

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

	stack_free(&stack_a);
	stack_free(&stack_b);
	return (0);
}
