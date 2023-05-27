#include "main.h"

/**
 * is_number - checks if a string is a number
 * @str: string to check
 * Return: 1 if true, 0 if false
 */
int is_number(char *str)
{
	int i;

	if (str == NULL)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		if (isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}

/**
 * free_stack - frees a stack
 * @stack: pointer to the stack
 * Return: void
 */
void free_stack(__stack_t *stack)
{
	__stack_t *current = stack;

	while (current != NULL)
	{
		current = current->next;
		free(stack);
		stack = current;
	}
}

/**
 * free_all - frees a stack and a file
 * @stack: pointer to the stack
 * @file: pointer to the file
 * Return: void
 */
void free_all(__stack_t *stack, FILE *file)
{
	free_stack(stack);
	fclose(file);
}

/**
 * get_op_func - selects the correct function to perform the operation
 * @s: operator passed as argument
 * Return: pointer to the function corresponding to the operator
 */
void (*get_op_func(char *s))(__stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"#", _nop},
		{"", _nop},
		{"\n", _nop},
		{NULL, NULL}};
	int i;

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(ops[i].opcode, s) == 0)
			return (ops[i].f);
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", globe.line_number, s);
	free_all(globe.stack, globe.file);
	exit(EXIT_FAILURE);
}

/**
 * split - splits a string into tokens
 * @str: string to split
 * @delim: delimiter
 * Return: pointer to an array of strings
 */
char **split(char *str, char *delim)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(globe.stack, globe.file);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		if (tokens[i][0] == '#')
		{
			tokens[i] = NULL;
			break;
		}
		i++;
	}

	return tokens;
}


