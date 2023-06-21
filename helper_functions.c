#include "monty.h"
/**
 * digits_only - not integer types are checked
 * @str: string
 * Return: 0 or 1
 */

int digits_only(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		if (isdigit(str[i]) == 0)
		{
			if (str[i] == '-' && i == 0)
				continue;
			return (0);
		}
	return (1);
}

/**
 * exec_loop - executes code commands
 * @a: buffers struct
 */

void exec_loop(buf_struct *a)
{
	stack_t *stack = NULL;
	int line_number = 1, i = 0;

	while (a->list_cmd[i])
	{
		split_spaces(a->list_cmd[i], a);
		if (strcmp(a->tok_cmd[0], "push") == 0)
		{
			if (!a->tok_cmd[1] || digits_only(a->tok_cmd[1]) == 0)
				a->tok_cmd[1] = "r";
			if ((strcmp(a->tok_cmd[1], "0") != 0 && atoi(a->tok_cmd[1]) == 0))
			{
				free_stack(stack);
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			else
				push(&stack, atoi(a->tok_cmd[1]));
		}
		else
		{
			if (get_op_func(a->tok_cmd[0]) == NULL)
			{
				free(stack);
				fprintf(stderr, "L%d: unknown cmd %s\n", line_number, a->tok_cmd[0]);
				exit(EXIT_FAILURE);
			}

			(*get_op_func(a->tok_cmd[0]))(&stack, line_number);
		}
		line_number++;
		i++;
	}
	free_stack(stack);
}

/**
 * get_op_func - function is selected
 * @s: func's name
 * Return: func's pointer
 */

void (*get_op_func(char *s))(stack_t **stack, unsigned int line_n)
{
	instruction_t cmd[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"pchar", pchar},
		{"rotl", rotl},
		{"mod", mod},
		{"queue", queue},
		{"pstr", pstr},
		{"nop", nop},
		{"rotr", rotr},
		{"mul", mul},
		{NULL, NULL}
	};
	int i = 0;

	while (cmd[i].opcode)
	{
		if (strcmp(s, cmd[i].opcode) == 0)
		{
			return (cmd[i].f);
		}
		i++;
	}
	return (NULL);
}
