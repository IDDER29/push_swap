#include "push_swap.h"
#include "ft_printf.h"

void print_stack(t_list *stack)
{
	int		i;
	t_node	*current;

	i = 0;
	current = stack->head;
	while (current != NULL)
	{
		ft_printf("Node %d: data=%d, index=%d, target=%d, cost=%d\n", i, current->data, current->index, current->target, current->cost);
		current = current->next;
		i++;
	}
	ft_printf("\n");
}
