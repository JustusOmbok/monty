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
