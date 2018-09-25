/*-------------------
CMPT360
Lab2
Yuhang Tian
3012401
--------------------*/
/*
#3. Write another program using fork(). The child process should print "hello"; the parent process should print "goodbye". You should try to ensure that the child process always prints first; can you do this without calling wait() in the parent? 

Yes, it can be done without calling wait() function, and child process always print first without using wait() function.
*/


#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void bye(int num) {
        printf("goodbye\n");
        exit(0);
}

int main (int argc, char const *argv[])
{	int p_pid = getpid();
	int rc = fork();
	//Parent process
	if (rc > 0)
        {       // using signal handler
                signal(SIGCONT, bye);
                pause();
        }

	// Child process
	else if (rc == 0)
        {       printf("hello\n");
                kill(p_pid, SIGCONT);
                exit(0);
        }

	// fork failed
	else
	{	printf("error\n");
		return 1;
	}
}


