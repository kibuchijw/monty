#include "monty.h"

/**
 * push_op - Pushes new element to stack
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: Parses integer from input, and creates new stack
 * The value is added on the top of stack
 *
 * Return: Nothing
 */

void push_op(stack_t **stack, unsigned int line_number)
{
	char *value = strtok(NULL, " \n\t");
	int num;
	stack_t *new_node;

	if (!value || (!isdigit(*value) && *value != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(value);
	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall_op - Prints all elements in stack
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: Prints all elements in stack, top to bottom
 *
 * Return: Nothing
 */

void pall_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint_op - Prints value at the top of stack
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: Prints value at top of stack without removing it
 *
 * Return: Nothing
 */

void pint_op(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop_op - Removes top element from stack
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: Removes top element from stack and frees memory
 *
 * Return: Nothing
 */

void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(top);
}

/**
 * swap_op - Swaps top two elements of stack
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: Swaps values of the top two elements of stack
 *
 * Return: Nothing
 */

void swap_op(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

