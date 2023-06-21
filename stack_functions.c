#include "monty.h"
/**
 * split_newline - read buffer is tokenized
 * @a: buffer's struct
 * Return: commands list
 */
char **split_newline(buf_struct *a)
{
	char delim[] = "\n";
	char *token;
	int i = 0;

	token = strtok(a->read_buff, delim);

	while (token != NULL)
	{
		a->list_cmd[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	if (a->list_cmd[0] == NULL)
		return (NULL);
	return (a->list_cmd);
}

/**
 * split_spaces - command is tokenized
 * @buff: commans indexes
 * @a: buff's strct
 * Return: command
 */

char **split_spaces(char *buff, buf_struct *a)
{
	char delim[] = " \t";
	char *token;
	int i = 0;

	token = strtok(buff, delim);
	while (token != NULL && i < 2)
	{
		a->tok_cmd[i] = token;
		token = strtok(NULL, delim);
		i++;
	}

	a->tok_cmd[i] = NULL;
	if (a->tok_cmd[0] == NULL)
		return (NULL);
	if (strncmp(a->tok_cmd[0], "#", 1) == 0)
		a->tok_cmd[0] = "nop";
	return (a->tok_cmd);
}

/**
 * free_stack - list is freed
 * @head: begining
 */

void free_stack(stack_t *head)
{
	stack_t *hold;

	while (head)
	{
		hold = head;
		head = (*head).next;
		free(hold);
	}
}
