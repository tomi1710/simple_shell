# simple_shell v2

## Description

This is a UNIX command line interpreter. It takes commands from the keyboard and gives them to the operating system to perform. In the old days, it was the only user interface available on a Unix-like system such as Linux. Nowadays, we have graphical user interfaces (GUIs) in addition to command line interfaces (CLIs) such as the shell.

On most Linux systems a program called bash (which stands for Bourne Again SHell, an enhanced version of the original Unix shell program, sh, written by Steve Bourne) acts as the shell program. Besides bash, there are other shell programs available for Linux systems.

Usage: ```simple_shell v2```

It:
Displays a prompt and waits for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. Arguments can be passed to programs.
If an executable cannot be found, prints an error message and displays the prompt again.
It can handle errors.
It also handles the “end of file” condition (Ctrl+D).
Handles the PATH.
Handles the exit built-in, that exits the shell.
Uses the env as a built-in, that prints the current environment.
Handles Ctrl+C: the shell does not quit when the user inputs ^C
Handles the builtin command cd (cd [directory], cd .. and cd).

## Getting started

### Compilation
This shell is compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

### Usage
It works both in interactive mode:
```
$ ./hsh
(<3) /bin/ls
hsh main.c shell.c
(<3)
(<3) exit
$
```
```
And in non-interactive mode:
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
## Executable commands
Input commands followed by an enter. Some examples shown below:

```
<3 ls -lah
<3 /bin/ls
<3 pwd
<3 mkdir hola
<3 cd hola
<3 cd ..
<3 rmdir hola
```
To exit program:

```
<3 exit
```

## File manifest
agregar tree de archivos

## Libraries included in this project
agregar lista

## Known bugs
None :)

## Restrictions
List of allowed functions and system calls:
- access
- chdir
- close
- execve
- fork
- stat (__xstat)
- lstat (__lxstat)
- fstat (__fxstat)
- kill
- open
- read
- signal
- wait
- waitpid
- wait3
- wait4
- write
- _exit
- dup
- dup2
- pipe
- unlink
- time
- gethostname
- geteuid
- sigaction
- sigemptyset
- select
- getpid
- __errno_location (errno macros)
- closedir
- exit
- free
- getcwd
- getline
- malloc
- opendir
- perror
- readdir
- strtok
- localtime
- getpwuid
- isatty
- printf
- fflush
- fprintf
- vfprintf
- sprintf

## Authors
Made by [Facundo Diaz](https://github.com/facu2279) and [Tomas de Castro](https://github.com/tomi1710) for Holberton School 2021 

## Social Networks

### Facundo Diaz

- [Linkedin](https://www.linkedin.com/in/facundo-diaz-noya/)
- Mail: ddiiaazzfacu@gmail.com
- [Github](https://github.com/facu2279)

### Tomas de Castro

- [Linkedin](https://www.linkedin.com/in/tomas-de-castro-guelfi-1872a1211/)
- Mail: tdecastroguelfi56@gmail.com
- [Github](https://github.com/tomi1710)