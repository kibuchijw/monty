#include "monty.h"

/**
 *main - This is the entry point of the monty interpreter.
 * The function first checks the No of arguments passed. If it they
 * are exactly 2, it calls the read_and_process function to get
 * instructions from appropriate files. If they are not exactly 2,
 * it prints a failure message and exits
 *
 *@argc: No of command-line arguments entered into the program
 *@argv: An an array of the command line arguments
 *
 *Return:
 *      EXIT_SUCCESS if instructions are passed appropriately
 *      EXIT_FAILURE if argument count is incorrect among other errors
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	read_and_process_file(argv[1]);
	return (EXIT_SUCCESS);
}

