#include "monty.h"
/**
 * pchar - char is printed according to ascii value
 * @stack: list's begining
 * @line_number: line no
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!(h->n > 64 && h->n < 91) && !(h->n > 96 && h->n < 123))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)h->n);
}

/**
 * pstr - string is printed based on ascii values
 * @stack: start of list linked
 * @line_number: line no
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	char string[1000];
	int i = 0;
	(void)line_number;

	memset(string, 0, 1000);
	if (!h)
		printf("\n");
	while (h)
	{
		if (!(h->n > 64 && h->n < 91) && !(h->n > 96 && h->n < 123))
		{
			break;
		}
		string[i] = (char)h->n;
		i++;
		h = h->next;
	}
	printf("%s\n", string);
}

/**
 * sub - removes last two elements
 * @stack: begining
 * @line_number: line no
 */

void sub(stack_t **stack, unsigned int line_number);
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_n);
}

/**
 * _div - divides top two elements
 * @stack: begining
 * @line_number: line no
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}
/**
 * mod - modulus of top two elements
 * @stack: begining
 * @line_number: line no
 */

void mod(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - multiplies top two elements
 * @stack: begining
 * @line_number: line no
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
