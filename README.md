# 0x16. C - Simple Shell

## Authors

-	Trevor Wamukoya
-	Peter Ochieng



```sh
-	By: Julien Barbier
-	Weight: 10
-	Project to be done in teams of 2 people (your team: Peter Ochieng, Trevor Wamukoya)
-	Project will start Apr 12, 2023 6:00 AM, must end by Apr 27, 2023 6:00 AM
-	Checker will be released at Apr 26, 2023 1:12 AM
-	An auto review will be launched at the deadline
```

<details>
<img src="https://user-images.githubusercontent.com/29776892/129798799-6f730688-8728-49ed-b01b-13bec0fa2896.jpeg">
<summary>The Gates of Shell by Spencer Cheng, featuring Julien Barbier</summary>

</details>

##Conceps

- [Everything you need to know to start coding your own shell](https://www.notion.so/C-Programming-f13cdb9661db464f8ea326c5a2654e8e)
- [Approaching a Project]( https://intranet.alxswe.com/concepts/350)



## Resource

- [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
- [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
- [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
- Everything you need to know to start coding your own shell concept page


----------------------------------------------------------------------
## man or help:

`sh` (Run `sh` as well)

## Learning Objectives

-	Who designed and implemented the original Unix operating system
-	Who wrote the first version of the UNIX shell
-	Who invented the B programming language (the direct predecessor to the C programming language)
-	Who is Ken Thompson
-	How does a shell work
-	What is a pid and a ppid
-	How to manipulate the environment of the current process
-	What is the difference between a function and a system call
-	How to create processes
-	What are the three prototypes of `main`
-	How does the shell use the `PATH` to find the programs
-	How to execute another program with the `execve` system call
-	How to suspend the execution of a process until one of its children terminates
-	What is EOF / “end-of-file”?


## Requirements

•	Allowed editors: `vi`, `vim`, `emacs`
•	All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
•	All your files should end with a new line
•	A `README.md` file, at the root of the folder of the project is mandatory
•	Your code should use the `Betty` style. It will be checked using `betty-style.pl` and `betty-doc.pl`
•	Your shell should not have any memory leaks
•	No more than 5 functions per file
•	All your header files should be include guarded
•	Use system calls only when you need to (why?)
•	Write a `README` with the description of your project
•	You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

## Output

- Unless specified otherwise, your program must have the exact same output as `sh` (`/bin/sh`) as well as the exact same error output.
- The only difference is when you print an error, the name of the program must be equivalent to your `argv[0]` (see below)

<details>
     <summary>Example of error with sh:</summary>
<pre>$ echo "qwerty" | /bin/sh<br>/bin/sh: 1: qwerty: not found<br>$ echo "qwerty" | /bin/../bin/sh<br>/bin/../bin/sh: 1: qwerty: not found<br>$</pre>
</details>

<details>
<summary>Same error with your program hsh:</summary>
<pre>$ echo "qwerty" | ./hsh<br>./hsh: 1: qwerty: not found<br>$ echo "qwerty" | ./././hsh<br>./././hsh: 1: qwerty: not found<br>$</pre>
</details>


<details>
<summary>List of allowed functions and system calls</summary>

+ `access` (man 2 access)
+ `chdir` (man 2 chdir)
+ `close` (man 2 close)
+ `closedir` (man 3 closedir)
+ `execve` (man 2 execve)
+ `exit` (man 3 exit)
+ `\_exit` (man 2 \_exit)
+ `fflush` (man 3 fflush)
+ `fork` (man 2 fork)
+ `free`(man 3 free)
+ `getcwd` (man 3 getcwd)
+ `getline` (man 3 getline)
+ `getpid` (man 2 getpid)
+ `isatty` (man 3 isatty)
+ `kill` (man 2 kill)
+ `malloc` (man 3 malloc)
+ `open` (man 2 open)
+ `opendir` (man 3 opendir)
+ `perror` (man 3 perror)
+ `read` (man 2 read)
+ `readdir` (man 3 readdir)
+ `signal` (man 2 signal)
+ `stat` (\_\_xstat) (man 2 stat)
+ `lstat` (\_\_lxstat) (man 2 lstat)
+ `fstat` (\_\_fxstat) (man 2 fstat)
+ `strtok` (man 3 strtok)
+ `wait` (man 2 wait)
+ `waitpid` (man 2 waitpid)
+ `wait3` (man 2 wait3)
+ `wait4` (man 2 wait4)
+ `write` (man 2 write)

</details>

<details>
<summary>The shell will be compiled this way:</summary>
<pre>$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \*.c -o hsh</pre>
</details>


## Testing

<details>
<summary>The shell should work like this in interactive mode:</summary>
<pre>$ ./hsh<br>($) /bin/ls<br>hsh main.c shell.c<br>($)<br>($) exit<br>$</pre>
</details>

<details>
<summary>But also in non-interactive mode:</summary>
<pre>$ echo "/bin/ls" | ./hsh<br>hsh main.c shell.c test\_ls\_2<br>$<br>$ cat test\_ls\_2<br>/bin/ls<br>/bin/ls<br>$<br>$ cat test\_ls\_2 | ./hsh<br>hsh main.c shell.c test\_ls\_2<br>hsh main.c shell.c test\_ls\_2<br>$</pre>
</details>

## Additions as we progress with the tasks
