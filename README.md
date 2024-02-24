# minishell
## as beutiful as a shell
As a starting point, it's worth noting that the term 'mini' doesn't fundamentally distinguish this project from a regular shell. While it may have fewer functionalities, at its core, it performs tasks similar to a standard shell.

## Table of Contents

1. [Requirement](#installation)
2. [Usage](#usage)
3. [Features](#features)
4. [Minishell Overview](#minishell-overview)
5. [Tokenization](#tokenization)
6. [Syntax Analysis](#syntax-analysis)
7. [Tree Construction](#tree-construction)
8. [Command Execution](#command-execution)
9. [License](#license)
10. [Credits](#credits)

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
The tokenization process in Minishell is designed to efficiently handle command input. The primary focus is on avoiding unnecessary data structures, such as linked lists, when extracting tokens. Instead, the tokenization is driven by three key functions:

### `int ft_get_token(char **line, char **token);`

- **line**: The address of the command line taken as input. It is passed by address since it will change with each function call.

- **token**: In C, returning two values from a function is not straightforward. The **token** parameter is used to store the actual token value.

- **Return Value**: The function returns an integer representing the type of the token. The defined token types are as follows:

  ```c
  #define T_OPRNTHS 1 // open parenthesis
  #define T_CPRNTHS 2 // close parenthesis
  #define T_AND     3 // and
  #define T_OR      4 // or
  #define T_PIPE    5 // pipe
  #define T_LESS    6 // <
  #define T_LLESS   7 // <<
  #define T_GREAT   8 // >
  #define T_GGREAT  9 // >>
  #define T_WORD   10 // word
  #define T_UNKNOWN 11 // unknown

### `int ft_get_word(char *s, int *j);`

The `ft_get_word` function is designed to extract a word from a string, handling various complexities. Examples of complexities include words within quotes or spaces between words. The function parameters are:

- **s**: The string from which the word is to be extracted.

- **j**: A pointer used to store the length of the extracted word.

- **Return Value**: If successful, the function returns 0. In case of failure, it returns -1.

This function is particularly useful in scenarios where words may contain special characters or spaces, ensuring accurate extraction for further processing in the tokenization process.
```"hello'world"itisme --> hello'world```

### int	ft_peak(char **line, char *toks);
the `ft_peak` function is designed to check whether the next non-whitespace character in the given string (*line) is present in a specified set of characters (toks).
- **line**: A pointer to a pointer to a string. The function uses a double pointer to be able to modify the original pointer and update it to the new position in the string.
- **toks**: A string containing characters to be checked.
- **Return Value**: If the next non-whitespace character in the string is found in the specified set of characters, it returns 1 (true). Otherwise, it returns 0 (false).
  
### int	ft_peak_2(char **line, char *toks);
This function is created to address the issue with `ft_peak`, where it might confuse between `|` and `||`.

## Syntax Analysis
In the context of Minishell, syntax analysis is performed using the concept of automata from language theory. In simple terms, an automaton takes a line of input and answers the question: Does this line belong to the language defined by Minishell?
Using automata in the syntax analysis allows for a systematic and rule-based approach to validate command structures. It ensures that the Minishell language is interpreted accurately, helping to prevent unexpected behavior and enhancing the user experience.
This implementation of automata aligns with language theory principles, making the syntax analysis robust and efficient for a wide range of Minishell commands.
The automata for the minishell : ![Automata](https://www.tldraw.com/r/ffGdtc9RCaHTHdnps295Z?viewport=-347,136,2560,1355&page=page:JP4s25SWsJkg2vwvLxRVt)

## Tree Construction

After making sure that the syntax is correct we move to build our tree :
The tree building is based on the folowing Grammer :
```
CMDLINE		--> PIPELINE
			--> PIPELINE "||" CMDLINE
			--> PIPELINE "&&" CMDLINE

PIPELINE	--> CMD 
			--> CMD "|" PIPELINE

CMD		--> BLOCK
		--> (REDIRECTION | word)+

BLOCK	--> "(" CMDLINE ")" ((">" | ">>") filename)*

REDIRECTION --> REDIRECTIONOP filename

REDIRECTIONOP	--> "<"
				--> ">"
				--> "<<"
				--> ">>"
```

## Command Execution
The building of the tree make the execution realy easy, just make sure to execute a single commande right and the whole commande line is just a recursive process
```c
void		ft_exc_and(t_cmdline *cmdline);
void		ft_exc_block(t_cmdline *cmdline);
void		ft_exc_cmd(t_cmdline *cmdline);
void		ft_exc_cmdline(t_cmdline *cmdline);
void		ft_exc_or(t_cmdline *cmdline);
void		ft_exc_pipe(t_cmdline *cmdline);




