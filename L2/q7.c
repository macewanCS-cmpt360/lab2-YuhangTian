/*-------------------
CMPT360
Lab2
Yuhang Tian
3012401
--------------------*/
/*
#7. Write a program that creates a child process, and then in the child closes standard output (STDOUT FILENO). What happens if the child calls printf() to print some output after closing the descriptor?
If the standard output file descriptor has been closed, we cannot write anything on the screen using printf() function.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{	int rc = fork();
	// Child process
	if (rc == 0)
	{	close(STDOUT_FILENO);
		printf("Showing child process.\n");
	}
	// Parent process
	else if (rc > 0)
	{	wait(NULL);
		printf("Showing parent process.\n");
	}
	else 
	{	printf("Processing fork() fail!\n");
	}
}

