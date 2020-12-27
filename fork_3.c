//Practical Q-3
/* Parent and child processes execute different programs */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	pid = fork();

	if (pid < 0){
		printf("Error!! Fork failed..no new process created.\n");
		return -1;
	}

	else if(pid==0){
		printf("This is the child process.\n");
		printf("In child: My process id: %d\n", getpid());
		printf("In child: We will load and execute the 'cat' command to display memory info. Once that is executed the child process will terminate.\n");
		execlp("/bin/cat", "cat", "/proc/meminfo", NULL);
		printf("execlp() in child failed!!\n");
	}

	else{
		printf("This is the parent process\n");
		printf("In parent: My process id: %d\n", getpid());
		printf("In parent: My child's process id: %d\n", pid);
		wait(NULL);
		printf("In parent: We will load and execute the 'ps -el' command to display the process statuses of the process existing. Once that is executed the parent process will terminate.\n");
		execlp("/bin/ps", "ps", "-el", NULL);
		printf("execlp() in parent failed!!\n");
	}

	return 0;
}