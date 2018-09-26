/*-------------------
CMPT360
Lab2
Yuhang Tian
3012401
--------------------*/


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(void){
	char *cmdline;
	char *token = NULL;
	int i, rc;
	char *args[10];
    
    cmdline = calloc(1, 1024);
    i = 0;
    /*
    printf("prompt> ");
    fgets(cmdline, 1024, stdin);
    fprintf(stderr, "[debug] cmdline = *%s*\n", cmdline);*/
    
	while (args[i]==NULL)
	{
		rc = fork();
        // check rc
		if (rc == 0)
		{	cmdline = calloc(1, 1024);
			i = 0;
			printf("prompt> ");
			fgets(cmdline, 1024, stdin);
			token = strtok(cmdline, "\n ");
			while (token != NULL)
			{	args[i++] = strdup(token);
				token = strtok(NULL, "\n ");
			}
			execvp(args[0],args);
			args[i] = NULL;
			free(cmdline);
		}
        //when rc < 0
		else if (rc < 0)
		{	fprintf(stderr,"Fork Failure\n");
		}
        //wait
		else
		{	int wait_rc = wait(NULL);
		}
	}
}
