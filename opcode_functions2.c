#include "monty.h"

/**
 * queue - linked list is flipped
 * @stack: stack's top
 * @line_number: line no
 */
void queue(stack_t **stack, unsigned int line_number)
{
	stack_t *flip = *stack, *hold = *stack;

	if (line_number)
		line_number = line_number;
	if (*stack && ((*stack)->next))
	{
		while (1)
		{
			hold = flip->next;
			flip->next = flip->prev;
			flip->prev = hold;
			if (hold != NULL)
				flip = hold;
			else
				break;
		}

		*stack = flip;
	}
}

/**
 * rotl - top becomes last, second element becomes top
 * @stack: top
 * @line_number: line no
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack, *head = *stack;

	if (line_number)
		line_number = line_number;
	if (head && head->next)
	{
		*stack = head->next;
		(*stack)->prev = NULL;
		for (; last->next; last = last->next)
			;
		last->next = head;
		head->next = NULL;
		head->prev = last;
	}
}

/**
 * rotr - last value goes top
 * @stack: top
 * @line_number: line no
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;

	if (line_number)
		line_number = line_number;
	if (*stack && (*stack)->next)
	{
		for (; last->next; last = last->next)
			;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}

/**
 * nop - nothing is done
 * @stack: not use
 * @line_number: not used
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)*stack;
	(void)line_number;
}

/**
 * add - top two elements are added
 * @stack: start of list
 * @line_number: line no
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't add, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_n);
}
