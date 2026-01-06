#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"

void calculate_cost(t_list *source, t_list *destination)
{
	t_node *curent_node;
	int cost;
	int s_cost;
	int d_cost;
	int rr_cost;
	int rrr_cost;

	cost = 99999;
	curent_node = source->head;

	while(curent_node !=NULL)
	{
		s_cost = curent_node->index % source->size;
		d_cost = curent_node->target % destination->size;
		if(s_cost > d_cost)
		{
			rr_cost = s_cost;
		}else
		{
			rr_cost = d_cost;
		}

		s_cost = source->size - curent_node->index % source->size;
		d_cost = destination->size - curent_node->target % destination->size;
		if(s_cost > d_cost)
		{
			rrr_cost = s_cost;
		}else
		{
			rrr_cost = d_cost;
		}

		if(curent_node->index < source->size / 2 && curent_node->target > destination->size / 2)
		{
			s_cost = curent_node->index % source->size;
			d_cost = destination->size - curent_node->target % destination->size;
			cost = s_cost + d_cost;
		}else if(curent_node->index > source->size / 2 && curent_node->target < destination->size / 2)
		{
			s_cost = source->size - curent_node->index % source->size;
			d_cost = curent_node->target % destination->size;
			cost = s_cost + d_cost;
		}

		if(rr_cost < rrr_cost && rr_cost < cost)
		{
			curent_node->cost = rr_cost;
		}else if(rr_cost >= rrr_cost && rrr_cost < cost)
		{
			curent_node->cost = rrr_cost;
		} else
		{
			curent_node->cost = cost;
		}
		curent_node = curent_node->next;
	}

}

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

	calculate_cost(&stack_b, &stack_b);

	ft_printf("STACK A :\n");
	print_stack(&stack_a);
	ft_printf("STACK B :\n");
	print_stack(&stack_b);
	
	stack_free(&stack_a);
	stack_free(&stack_b);
	return (0);
}
