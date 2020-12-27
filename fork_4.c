//Practical Q-4
/* Parent process waits for the child process to terminate before terminating itself */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	pid = fork();

	if (pid < 0)
	{
		printf("Error!! Fork failed..no new process created.\n");
		return -1;
	}

	else if(pid == 0){
		printf("\nThis is the child process\n");
		printf("In child: My process id: %d\n", getpid());
		printf("In child: My parent's process id: %d\n", getppid());
		sleep(5);
		printf("In child: After sleep() command's execution in child, the child process now terminates..\n");
	}

	else{
		printf("\nThis is the parent process\n");
		printf("In parent: My process id: %d\n", getpid());
		printf("In parent: My parent's process id: %d\n", getppid());
		printf("In parent: My child's process id: %d\n", pid);
		wait(NULL);
		printf("The child process has terminated and the parent process now terminates\n");
	}
	return 0;
}