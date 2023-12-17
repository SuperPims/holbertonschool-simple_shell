#include "lib.h"

/**
 * free_tokens - Free the memory allocated for an array of tokens.
 * @tokens: An array of strings to be freed.
 *
 * This function takes an array of strings and frees the memory for each
 * individual string and the array itself. It checks if the 'tokens' array is
 * NULL to avoid dereferencing a NULL pointer.
 */

void free_tokens(char **tokens)
{
	int i = 0;

	if (!tokens)
		return;

	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

/**
 * handle_input - Handle user input in the interactive mode.
 * @input: The user input string.
 *
 * This function tokenizes the input, checks for
 * specific commands like "exit,"
 * and executes the input as a command using execmd
 * if it's not an exit command.
 * It also frees the memory allocated for tokens.
 */

void handle_input(char *input)
{
	char **tokens = tokenize_line(input, " \t\n");

	if (tokens && tokens[0])
	{
		if (strcmp(tokens[0], "exit") == 0)
		{
			free_tokens(tokens);
			exit(0);
		}

		execmd(tokens);
		free_tokens(tokens);
	}
}

/**
 * interactive_mode - Run the interactive mode of the shell.
 *
 * This function starts an interactive shell session that continuously prompts
 * the user for input, tokenizes the input, and handles the execution of
 * commands. It terminates when the user enters the end-of-file
 * character (EOF).
 * Memory allocated for 'input' is freed at the end.
 */

void interactive_mode(void)
{
	char *prompt = "s_shell $ ";
	char *input = NULL;
	size_t n = 0;

	while (1)
	{
		printf("%s", prompt);
		if (getline(&input, &n, stdin) == -1)
		{
			printf("This Is The Way\n");
			break;
		}

		handle_input(input);
	}

	free(input);
}
