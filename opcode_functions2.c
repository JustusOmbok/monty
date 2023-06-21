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
