#include <stdio.h>
#include <string.h>

#include "TinyShell.h"

#define USER_INPUT_MAX (200)

tinyshell_err_t handle_help_cmd(size_t argc, char* argv[]) {
	(void)argc;
	(void)argv;

	printf("Usage: <cmd> [arg [...]]\r\n");

	return TINYSHELL_NOERR;
}

int main(int argc, char* argv[]) {
	(void)argc;
	(void)argv;

	tinyshell_err_t err = 0;

	while (1) {
		printf("$ ");

		char user_input[USER_INPUT_MAX] = {0};
		fgets(user_input, USER_INPUT_MAX, stdin);

		// Remove newline if exists because it messes with command parsing.
		if (
			strlen(user_input) > 0 &&
			user_input[strlen(user_input) - 1] == '\n'
		) {
			user_input[strlen(user_input) - 1] = '\0';
		}

		if (strcmp((const char*)user_input, "exit") == 0) {
			break;
		}

		err = tinyshell_parse((const char*)user_input);
		if (err) {
			printf("[TinyShell][ERROR]: %d\r\n", err);
		}
	}

	return 0;
}
