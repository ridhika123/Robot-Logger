# Robot Logger

## Prompt

#### Summary: 
You will write a "robot logger" program which can log actions to a file, and also read and perform actions from a file.

#### Details:
You should use command-line input flags to specify whether the robot is in "read" mode (reading actions from a file), "write" mode (logging actions onto a file), or both "read" and "write" mode. When no files or flags are specified, I/O should happen through the terminal.

In particular:

* If the user specifies a command-line flag -w, then
  * if the following command-line argument does not start with a hyphen (indicating it is a flag), then that argument should be used as the name of the file for writing. However, if no file name is given, the program should ask the user for a file name.
  * the program should perform the given commands, and
  * the program should log the commands in the specified file.
* If the user specifies a command-line flag -r, then
  * if the following command-line argument does not start with a hyphen (indicating it is a flag), then that argument should be used as the name of the file for reading. However, if no file name is given, the program should ask the user for a file name.
  * the program should read commands from the specified file, and
  * the program should perform the commands. 
* If the user does not specify the command-line flag -r, then
  * the program should read commands from the user via standard input, and
  * the program should perform those commands.
* it should be possible for a user to utilize both -w and -r mode.
* the program should not print a prompt for robot commands; instead
* if the user specifies a command-line flag -h, then the program should list the possible actions (i.e., the command file or input format) and exit 

This program should support at least 10 different actions (following the previous [Project](https://github.com/ridhika123/Robot-Command) command requirements). As with that project, each action (except, perhaps, quit) must be implemented as a separate procedure.

#### Example:
The following examples are based on a program robot-command that supports this project. Although this table shows several possibilities, the table is not complete. For example, various combinations of -r and -w are possible, with and without file names, and the -r and -w flags could be in either order.

    Command line	      Interpretation
    ./robot-command	    no command-line arguments, so reads from stdin and writes to stdout (facilitates shell redirection)
    ./robot-command -r  infile.dat	reads commands from file infile.dat; writes to stdout
    ./robot-command -r	reads from a file; because no filename is given on the command line, program must ask user what file to use; program writes to stdout
    ./robot-command -w  logfile.dat	reads from stdin; writes commands with parameters to file logfile.dat
    ./robot-command -w	reads from stdin; writes commands with parameters to a file; because no file name is given on command line, program must ask what file to use
    ./robot-command -w  logfile.dat -r infile.dat
    OR
    ./robot-command -r  infile.dat -w logfile.dat	reads commands from infile.dat, writes commands with parameters to logfile.dat
    ./robot-command -r  infile.dat -w	reads commands from infile.dat; writes comands with parameters to a file; because no log file name is specified, user must be asked for the filename

#### Notes:
* Global variables may not be used in this project; use of any global variable will result in a grade of zero. Instead, use parameters to pass values into functions.
* You are encouraged to use Project 3 or your command-robot.c program from the Command-Line Arguments lab as the basis for the command input. (You must clearly identify which code is original to a different work and who the authors are.)
* Remember that stdin and stdout are themselves FILE* variables and can be passed to functions that expect a variable of that type.

## Response
The program is [here](https://github.com/ridhika123/Robot-Logger/blob/main/robot_logger.c).
