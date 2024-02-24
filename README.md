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

### `&&` and `||` with parenthesis for priorities
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

## Minishell Overview

The Minishell project is designed to parse commands, build a tree structure, and execute them, closely mirroring the functionality of the 'bash' shell. The process involves several key steps:

1. **Tokenization** #Tokenization: The command is initially tokenized to break it down into individual components, facilitating further analysis.

2. **Syntax Analysis** #Syntax Analysis: The syntax of the command is then analyzed to ensure it adheres to the shell syntax. This step is crucial for correctly interpreting user input.

3. **Tree Construction** #Tree Construction: A tree structure is constructed to represent the command. This tree serves as a logical representation that aids in the execution process.

4. **Command Execution** #Command Execution: The parsed and analyzed command is executed based on the constructed tree. This step involves handling various signals, including Ctrl-C, Ctrl-D, Ctrl-Z, and Ctrl-\, to emulate the behavior of the 'bash' shell.
  
5. **Redo**

This complex process ensures that the Minishell performs command parsing and execution seamlessly, providing a shell experience similar to established counterparts.

## Tokenization
for tokenization we try try to ply it smart, ther is no need to buit a whole linked list just for some data about tokens, let's take the folowing example ``` bash ls | ||||||| &&&&&&& gd &&&&&&&&&&&    d ()```
if we use the linked list or any similar approach, we end up with a linked list of token that are syntaxecly wrong, while we could stop our tokenzing process at the first `or` after `pipe` : ```bash ls | ||```
The idea is simple our tokenzer is based on three function :
> ```c int	ft_get_token(char **line, char **token);```
- - `line` : the address of the command line we took as ann input, not thate we pass the line by address because it is goining to change every time we call the function
  - `token` : in C language we can not return two values from  a function, so **token** is used to hold the values of the actual token
  - this function return an int representing the type of the token
```c
# define T_OPRNTHS 1 // open paranthesis
# define T_CPRNTHS 2 // close paranthesis
# define T_AND 3 // and
# define T_OR 4 // or
# define T_PIPE 5 // pipe
# define T_LESS 6 // < 
# define T_LLESS 7 // <<
# define T_GREAT 8 // >
# define T_GGREAT 9 // >>
# define T_WORD 10 //
# define T_UNKNOWN 11
```
> ```c int	ft_get_word(char *s, int *jj);```
> ```c  int	ft_peak(char **line, char *toks);```
> ```c int	ft_peak_2(char **line, char *toks);```
