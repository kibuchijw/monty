#include "monty.h"

/**
 * nop_op - Does nothing
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: The opcode doesn't perform any action
 * deals with no-operation instruction
 *
 * Return: Nothing
 */

void nop_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;       /* Unused parameter */
	(void)line_number; /* Unused parameter */
}
/**
 * pchar_op - Prints ASCII characteer of top value on stack
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: Prints ASCII character of the top value on the stack.
 * If stack is empty or value is out of ASCII range,
 * prints error message, and removed top value from stack
 *
 * Return: Nothing
 */

void pchar_op(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
	pop_op(stack, line_number);
}

/**
 * pstr_op - Prints ASCII characters from stack as a string
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: Prints ASCII characters matching values on the stack
 * from top and print character until value is 0 or stack is empty.
 *
 * Return: Nothing
 */

void pstr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number; /*Unused parameter*/

	current = *stack;
	while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
/**
 * rotl_op - Rotates stack to the top
 * @stack: Pointer to the stack
 * @line_number: Current line number in file
 *
 * Description: Moves top value of stack to the bottom, while
 * shifting the rest up.
 *
 * Return: Nothing
 */
void rotl_op(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	(void)line_number; /* Unused parameter */

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;

		while (first->next)
		{
			first = first->next;
		}
		(*stack)->next = NULL;
		first->next = *stack;
		second->prev = NULL;
		*stack = second;
	}
}

/**
 * rotr_op - Rotates stack to the bottom
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: Moves bottom value of stack to top while shifting the
 * rest down.
 *
 * Return: Nothing
 */

void rotr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)line_number; /* Unused parameter */

	if (*stack && (*stack)->next)
	{
		last = *stack;
		while (last->next)
		{
			last = last->next;
		}

		last->prev->next = NULL;
		last->next = *stack;
		last->prev = NULL;
		(*stack)->prev = last;
		*stack = last;
	}
}

