Author: Jesus Gonzalez

OVERVIEW:
------------------------------------------------------------
This script imitates the effects of some unix/linux commands
When compiled/ran, it can be run with/without parameters.
------------------------------------------------------------

RUNNING CONFIGURATIONS: 
------------------------------------------------------------
alone : Will print out all the visible contents of current directory
-h flag : Will print all (including invisible) files of the current directory
directory name: Will print all files inside of that directory
------------------------------------------------------------

RUNNING EXAMPLES:
-------------------------------------------------------------
alone: 		a.out, ./a.out, or myls 
-h flag:	a.out -h, .a.out -h, or myls -h
directory: 	a.out my_dir, ./a.out my_dir, or myls my_dir
-------------------------------------------------------------

EXTRA NOTES:
-------------------------------------------------------------
note: that there is also a makefile available, when it is maked,
myls will replace the a.out nonsense!

to make just type: make -f makefile on the command line