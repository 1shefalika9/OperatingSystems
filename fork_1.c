/*WHEN U HAVE MULTIPLE CHILDREN OF A PROCESS THE'NULL' VALUE IN wait(NULL) 
says that when at least one child process has terminated the parent process awakens and finishes*/

//when wait() returns pid -1 it means that there are no more child processes of the parent process

/*pid = wait(&status) waits for one child process to terminate (ie. it returns the status and pid of the child process that 
has terminated) so to wait for all child processes to terminate u'll have to write this statement again and again
or u can use a while loop*/
// do{
// 	pid =  wait(&status);
// }while(pid != -1);

#include <stdio.h>
#include <sys/types.h> 	//for pid_t
#include <unistd.h>		//for fork()
#include <wait.h>	//for wait system call

int main(int argc, char const *argv[])
{
	pid_t pid1, pid2;
	pid1 = fork();
	pid2 = fork();

	if (pid1 < 0 || pid2<0)
	{
		printf("\nError..fork failed for at least one child!!");
		return -1;
	}

	else if(pid1 == 0){
		printf("\nThis is the child process\n");
		printf("In child: My process' id: %d\n", getpid());
		sleep(5);
		printf("In child: My parent process' id: %d\n", getppid());
	}

	else{
		printf("\nThis is the parent process\n");
		printf("In parent: My process' id: %d\n", getpid());
		printf("In parent: My parent process' id: %d\n", getppid());
		printf("In parent: My child process' id: %d\n", pid);
		wait(NULL);
		printf("Child process has terminated. Now the parent process terminates.\n");
	}

	return 0;
}