#include <stdlib.h>
#include "push_swap.h"

void stack_init(t_list *stack)
{
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
}

int create_node(t_list *stack, int data)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (-1);

	new_node->data = data;
	new_node->index = -1;
	new_node->target = -1;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (stack->size == 0)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		stack->tail->next = new_node;
		new_node->prev = stack->tail;
		stack->tail = new_node;
	}
	stack->size++;
	return (0);
}

void stack_free(t_list *stack)
{
	t_node *current;
	t_node *next;

	current = stack->head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}
