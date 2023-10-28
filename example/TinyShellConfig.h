#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/** User-editable configuration file for TinyShell. */

/** @brief TinyShell error codes. */
typedef enum {
	TINYSHELL_NOERR = 0,
	TINYSHELL_ERR_UNRECOGNIZED
} tinyshell_err_t;

/** @brief Amount of supported shell commands. */
#define TINYSHELL_CMD_COUNT (1)

/** @brief Max amount of supported arguments to a command. */
#define TINYSHELL_CMD_ARG_COUNT (5)

/**
 * @brief List of command handlers in TINYSHELL_CMD_HANDLER(command, function) pairs.
 *
 * @note Define the handlers akin to this in a source file (non-static!):
 *       tinyshell_err_t function(size_t argc, char* argv[]);
 */
#define TINYSHELL_HANDLERS \
	TINYSHELL_CMD_HANDLER("help", handle_help_cmd) \

#ifdef __cplusplus
}
#endif
