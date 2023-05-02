# Makefile-Tutorial


## Special Functions

 **patsubst**
  -	patsubst is used to substitute a pattern with another pattern in a list of words, which can be useful in various scenarios. Here's a summary of what I found in the sources:
	- `$(patsubst pattern,replacement,input)`

- **Wildcard** is used to expand the list of files that match one of the given file name patterns. The wildcard function is used anywhere in a makefile and is replaced by a space-separated list of names of existing files that match one of the given file name patterns. 
    - `$(wildcard *.c)` will get a list of all the C source files in a directory.

## Automatic Variables
Here is a table of automatic variables:

- `$@` The file name of the target of the rule.
- `$%` The target member name
- `$<` The name of the first prerequisite
- `$?` The names of all the prerequisites that are newer than the target
- `$^` The names of all the prerequisites
- `$+` This is like ‘$^’, but prerequisites listed more than once are duplicated in the order they were listed in the makefile.