# minishell
## as beutiful as a shell
As a starting point, it's worth noting that the term 'mini' doesn't fundamentally distinguish this project from a regular shell. While it may have fewer functionalities, at its core, it performs tasks similar to a standard shell.

## Table of Contents

1. [Requirement](#installation)
2. [Usage](#usage)
3. [Features](#features)
4. [Contributing](#contributing)
5. [License](#license)
6. [Credits](#credits)

## Reqirement
- c compiler (Ensure to adjust the compiler in the makefile to match the one you are using)
  > `CC = cc`
- Ensure that you have 'make' installed before proceeding with the build process.
- readline library

## Usage

- clone the reposetory
- `make`
- `./minishell`
you should be able to see a prompt like this : `minishel1 $>`

## Features

### && and || with parenthesis for priorities
```bash
minishel1 $> false && echo "minishell" || pwd
minishell $> (true || pwd) && (echo "hello" || ls -la)
```

### Pipes `|` 
```bash
minishel1 $> cat * | grep .c | wc -l # count the number of .c files
```

### I/O Redirections (`<`, `<<`, `>` and `>>`)
```bash
minishel1 $> << he cat | grep 'ft_' > output
```

### Built-in Commands
```bash
echo    # Write arguments to the standard output.
cd      # Change the shell working directory.
pwd 	  # Print the name of the current working directory.
export 	# Set export attribute for shell variables.
unset 	# Unset values and attributes of shell variables.
env 	  # Set environment and execute command, or print environment.
exit	  # Exit the shell.
true, false  # Just to test the conditionals
```
