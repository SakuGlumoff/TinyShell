# TinyShell
Lightweight portable shell for embedded systems.

## Usage
Create a `TinyShellConfig.h` and include the file `TinyShell.h` in your project.
An example of the config file can be found in `example/TinyShellConfig.h`.
Then add `src/TinyShell.c` to your project's sources.

Whenever you receive input from the user, call
`tinyshell_err_t tinyshell_parse(const char* input)` which will parse the input
and call the command handlers (callbacks) which you specified in the `TinyShellConfig.h`.

The user input is in format:
```bash
<cmd> [arg [...]]
```

## NOTE!
_TinyShell_ relies on `strchr` and `strncmp` from `<string.h>`!
