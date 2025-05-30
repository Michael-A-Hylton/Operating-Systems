Group Number: Group 12
Group Member: Michael Hylton 2788154
Contribution: 63%/37%

Design Idea: Create a code that takes input from the user while displaying the current directory as a prompt. Then if the user types cd, change the current directory. If the user types path, it would display current environment path. Path + adds to it and path - removes a path from it. if the user types Quit (which needs to be outside the fork), needs to break out of the loop and end the program. Lastly, it needs to be able to redirect input to a file or redirect output to a file.

To compile the program, I use the following command: gcc (insert filepath here)/project1.c -o project1 
though you will have to replace the path with the path you saved the code to.
and then I run the program using ./project1

Here is a sample of how to run:

	./project1
	/home/michael-hylton:~$ cd
	cd command requires a directory argument.
	/home/michael-hylton:~$ cd /home/michael-hylton/Desktop

	Current Directory: /home/michael-hylton/Desktop
	/home/michael-hylton/Desktop:~$ path 

	Current Directories: (empty)

	/home/michael-hylton/Desktop:~$ path + /bin


	Appending /bin



	Full Path Environment: /bin:

	/home/michael-hylton/Desktop:~$ path + /bin/sh
	Appending /bin/sh



	Full Path Environment: /bin:/bin/sh:

	/home/michael-hylton/Desktop:~$ path - /bin/sh


	Removing Pathname /bin/sh


	Removing /bin/sh: from /bin:/bin/sh:
	New Pathname: /bin:


	/home/michael-hylton/Desktop:~$ path

	Current Directories: /bin:

	/home/michael-hylton/Desktop:~$ quit

	Quitting now...


