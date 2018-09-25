/*-------------------
CMPT360
Lab2
Yuhang Tian
3012401
--------------------*/
/*
#2. Write a program that opens a file (with the open() system call) and then calls fork() to create a new process. Can both the child and parent ac- cess the file descriptor returned by open()? What happens when they are writing to the file concurrently, i.e., at the same time?

Both child and parent can access the file descriptor opened by using open() function.
Both child and paren can write to the file but not in a deterministic order.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
int main(){
	struct stat sb;
	int new_file = open("new.txt", O_CREAT | O_RDWR, S_IRWXU);
	int rc = fork();
	if (rc == 0)
	{	const char * child_msg = "Child processed!\n";
		write(new_file, child_msg , strlen(child_msg));
		exit(0);
	}

	else if (rc > 0)
	{	wait(NULL);
		const char * parent_msg = "Parent processed!\n";
		write(new_file, parent_msg, strlen(parent_msg));
	}
	fstat(new_file, &sb);
	lseek(new_file, 0, SEEK_SET);
	char * buffer = malloc(sb.st_size);
	read(new_file, buffer, sb.st_size);
	printf("Written information on new.txt: \n%s", buffer);
	close(new_file);
	return 0;
}



