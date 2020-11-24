# Simple_shell

Simple_shell is a project created to simulate a command interpeter. In it you can write the usual commands as an standart input to be executed.

## File Contents
This repository contains the following files:

|   **File**   |   **Description**   |
| -------------- | --------------------- |
| simple_shell.c | main function |
| shell.h | header file |
| string.c | functions to work with strings, concatenate, etc. |
| AUTHORS | creators |
| man_1_simple_shell | man page |

# To utilize this shell, follow the next steps:

## Clone the repository

This way you will have all the files necessary.

```
$ git clone https://github.com/ChloeDumit/simple_shell
```

## Compile it and start

To start simple_shell you just need to compile using.

```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh.
```

### Start the shell!

```
./hsh
```

## How to use it:

```
hsh$ /bin/ls
hsh$ ls -la
hsh$ pwd
```
## Commands
|   **Command**   |   **Description**   |
| -------------- | --------------------- |
| ls [option] | List directory contents. |
| pwd | List working directory. |
| cd [PATH] | Change directory. |
| cp | Copy Files. |
| mv | Move files. |
| Ctrl + C | The simple shell will be terminated. |
| Ctrl + D | The simple shell will be terminated. |

## Builtins
|   **Command**   |   **Description**   |
| -------------- | --------------------- |
| env |  Run a program in a modified enviroment. |
| exit | Cause normal process termination. |

## Authors
Tomas de Castro
Gabriel Prochnau
