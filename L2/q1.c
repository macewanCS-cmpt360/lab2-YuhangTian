/*-------------------
CMPT360
Lab2
Yuhang Tian
3012401
--------------------*/

/*
#1. Write a program that calls fork(). Before calling fork(), have the main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? What happens to the variable when both the child and parent change the value of x? 
	The value of number is 100 in the child process. The fork() function creates a copy of parent process. However, the child and parent process have their own private address space exclusive of each other. Both child and parent processes cannot interfere in each other's address space. Therefore, each one of them will keep their own copy of variables.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int vx;
	vx = 100;
	int rc = fork();
	// Child process
	if (rc == 0)
	{	printf("The child process\n");
		printf("The value of X: %d\n", vx);
		vx = 200;
		printf("New Value of X: %d\n", vx);
	}
	// Parent process
	else if (rc > 0)
	{	wait(NULL);
		printf("The parent process\n");
		printf("The value of X: %d\n", vx);
		vx = 300;
		printf("New Value of x: %d\n", vx);
	}
	//Error return
	else
	{	fprintf(stderr, "Error occur when creating the process!");
	}
}
