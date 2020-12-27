//Practical Q-5
/* creating a hierarchy of processes */
/*including wait() in P1 (for P2 and P4) and wait in P2 (for P3) so their respective parent process id doesn't become 1 (that of init)
if their parent processes terminate before */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char const *argv[])
{
	pid_t pid1, pid2, pid3;

	pid1= fork();

	if(pid1 < 0){
		printf("Error!! Fork failed..no new process created.\n");
		return -1;
	}

	else if(pid1 == 0){
		printf("This is the first child process of process P1. We name it- P2\n");
		pid2 = fork();
		if (pid2 < 0)
		{
			printf("Error!! Fork failed..no new child process of process P2 created.\n");	
			return -1;
		}
		else if (pid2 == 0)
		{
			printf("This is the child process of process P2 and grandchild of process P1. We name it- P3\n");
			printf("Inside P3: my process id: %d\n", getpid());
			printf("Inside P3: my parent's process id (pid of P2): %d\n", getppid());
		}
		else{
			printf("Inside P2: my process id: %d\n", getpid());
			printf("Inside P2: my parent's process id (pid of P1): %d\n", getppid());
			wait(NULL);
			printf("Process P2 now terminates after the termination of its child P3\n");
		}
	}

	else{
		printf("This is the main parent process (P1)\n");
		pid3 = fork();
		if (pid3 < 0)
		{
			printf("Error!! Fork failed..no new child process of process P1 created.\n");	
			return -1;
		}
		else if (pid3 == 0)
		{
			printf("This is the second child process of process P1. We name it- P4\n");
			printf("Inside P4: my process id: %d\n", getpid());
			printf("Inside P4: my parent's process id (pid of P1): %d\n", getppid());
		}
		else{
			printf("Inside P1: my process id: %d\n", getpid());
			printf("Inside P1: my first child's process id (pid of P2): %d\n", pid1);
			printf("Inside P1: my second child's process id (pid of P4): %d\n", pid3);
			pid_t pid;
			int status;
			do{
				pid =  wait(&status);
			  } while(pid != -1);
			printf("Parent process P1 now terminates after the termination of its children P2 and P4\n");
		}
	}

	return 0;
}