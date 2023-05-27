#include "main.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _add(__stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all(*stack, globe.file);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	_pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * _nop - does nothing
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _nop(__stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _sub - subtracts the second top element of the stack from the top element
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _sub(__stack_t **stack, unsigned int line_number)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all(*stack, globe.file);
		exit(EXIT_FAILURE);
	}

	sub = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = sub;
}

/**
 * _div - divides the top element of the stack by the second top element
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _div(__stack_t **stack, unsigned int line_number)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_all(*stack, globe.file);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(*stack, globe.file);
		exit(EXIT_FAILURE);
	}

	div = (*stack)->next->n / (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = div;
}

/**
 * _mul - multiplies the top element of the stack with the second top element
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _mul(__stack_t **stack, unsigned int line_number)
{
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all(*stack, globe.file);
		exit(EXIT_FAILURE);
	}

	mul = (*stack)->n * (*stack)->next->n;
	_pop(stack, line_number);
	(*stack)->n = mul;
}

