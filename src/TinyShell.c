#include <string.h>

#include "TinyShell.h"

/** @brief TinyShell command array item structure. */
typedef struct {
	const char* id;
	tinyshell_cmd_t func;
} tinyshell_cmd_arr_t;

#define TINYSHELL_CMD_HANDLER(cmd, func) extern tinyshell_err_t func(size_t, char*[]);
/** Create extern definitions for the command handlers. */
TINYSHELL_HANDLERS
#undef TINYSHELL_CMD_HANDLER

static const tinyshell_cmd_arr_t tinyshell_cmds[TINYSHELL_CMD_COUNT] = {
#define TINYSHELL_CMD_HANDLER(cmd, func) {cmd, func},
/** Populate the command handler array. */
TINYSHELL_HANDLERS
#undef TINYSHELL_CMD_HANDLER
};

tinyshell_err_t tinyshell_parse(const char* input) {
	tinyshell_err_t err = TINYSHELL_ERR_UNRECOGNIZED;

	size_t argc = 0;
	char* argv[TINYSHELL_CMD_ARG_COUNT] = {0};
	char* p_arg = (char*)input;

	while (p_arg != NULL && argc < TINYSHELL_CMD_ARG_COUNT) {
		argv[argc] = p_arg;
		p_arg = strchr((const char*)p_arg+1, ' ');
		if (p_arg != NULL) {
			*(p_arg++) = '\0';
		}
		argc++;
	}

	for (size_t i = 0; i < TINYSHELL_CMD_COUNT; i++) {
		if (strncmp(tinyshell_cmds[i].id, input, strlen(tinyshell_cmds[i].id)) == 0) {
			err = tinyshell_cmds[i].func(argc, argv);
			break;
		}
	}

	return err;
}
