//Practical Q-1
/* Parent and child processes execute the same lines of code */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	pid = fork();

	if (pid < 0){
		printf("Error!! Fork failed..no new process created.\n");
		return -1;
	}

	else{
		printf("Success!! fork() worked.\n");
	}
	
	return 0;
}