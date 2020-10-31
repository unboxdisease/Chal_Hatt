**NAME** : kushal Kumar Jain 
**ROLL-NO.** : 2019111001
>How to run
- run *make* on command line
- start shell with *./a.out*

>Files

- **header.h** : Contains all the header file , variable , function declarations.
- **main.c** : Contains the main loop and some array declarations and making of history file.
- **prompt.c** : prints the username , machine name and current working directory of the user.
- **echo.c** : Print given input on the console.
- **execute.c** : Finds which command is to be executed and calls the appropriate function.
- **command.c** : takes input, converts input into command and its corresponding arguements.
- **forking.c** : executes commmands that are not defined in execute.c , sends & commands to background.
- **ls.c** : Prints details of files in provided dirctory with various flags.
- **pinfo.c** : Prints process id , memory , status and executable path.
- **makefile** : Compiles all the .c files to give an executable file.
- **history.c** : Stores all the typed commands in a file named history in the same directory as the a.out file. It also prints 10 of the last of them on request.
