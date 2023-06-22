#include "monty.h"

/**
 * set_op_tok_error - Sets last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void set_op_tok_error(int error_code)
{
	int toks_len = token_arr_len();
	int i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;
	

	toks_len++;
	new_toks = malloc(sizeof(char *) * (toks_len + 1));
	if (new_toks == NULL)
	{
		malloc_error();
		return;
	}
	for (i = 0; i < toks_len - 1; i++)
	{
		new_toks[i] = op_toks[i];
	}

	exit_str = get_int(error_code);
	if (exit_str == NULL)
	{
		free(new_toks);
		malloc_error();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
