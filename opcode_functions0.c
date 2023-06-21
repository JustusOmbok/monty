#include "monty.h"
#include <stdlib.h>

/**
 * push - node is added
 * @head: begining
 * @n: new nod's value
 * Return: added node
 */

stack_t *push(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		if (*head != NULL)
			free_stack(*head);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = *head;
	new->prev = NULL;

	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}

/**
 * pall - prints list
 * @stack: start
 * @line_number: line number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (!stack)
	{
		fprintf(stderr, "L%d: can't pall, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (; h; h = h->next)
		fprintf(stdout, "%d\n", h->n);
}

/**
 * swap - top two elements are swapped
 * @stack: first node
 * @line_number: line no
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int hold = (*stack)->n;

	if (!(stack) || !(stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = hold;
}

/**
 * pop - first node removed from list
 * @stack: first node
 * @line_number: line no
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *delete = *stack;

	if (!delete)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = delete->next;
	free(delete);
}

/**
 * pint - first node of list is printed
 * @stack: first node
 * @line_number: line no
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (!h)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", h->n);
}
