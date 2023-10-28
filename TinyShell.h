#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#include "TinyShellConfig.h"

/**
 * @brief TinyShell command callback.
 *
 * @param argc Amount of arguments in the command (including the command itself).
 * @param argv List of arguments in the command.
 *
 * @return tinyshell_err_t Error code.
 */
typedef tinyshell_err_t (*tinyshell_cmd_t)(size_t argc, char* argv[]);

/**
 * @brief Parse input for TinyShell.
 *        If a matching command is found from TINYSHELL_HANDLERS,
 *        it calls the respective handler.
 *
 * @see TinyShellConfig.h#TINYSHELL_HANDLERS
 *
 * @param input String of data to parse.
 *
 * @return TINYSHELL_NOERR if successful, something else if not.
 */
tinyshell_err_t tinyshell_parse(const char* input);

#ifdef __cplusplus
}
#endif
