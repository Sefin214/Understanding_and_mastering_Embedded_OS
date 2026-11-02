#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define SIZE 1024

int main(){
	int pipefd[2];
	pid_t pid;
	char message[] = "Hi, this is Sefin.\n";
	char buffer[SIZE];

	//creating pipe
	if(pipe(pipefd) == -1){
		printf("Pipe creation failed");
		return -1;
	}

	pid = fork();
	if(pid<0){
		printf("Fork Failed! Child process not generated");
		close(pipefd[1]);
		return -1;
	}
	
	//Child process
	if(0 == pid){
		close(pipefd[0]);  //closed the reading end
		ssize_t bytes_written = write(pipefd[1],message,sizeof(message));
		if(-1 == bytes_written){
			printf("Error occured whille writing; Bytes not written!\n");
		return -1;
		}
		close(pipefd[1]);
	}
	else{
	//parent process
	close(pipefd[1]);  //closed the writing end
	ssize_t bytes_read = read(pipefd[0], buffer, SIZE);
	if(-1 == bytes_read){
		printf("Error occured while reading; Bytes not read!\n");
		return -1;
	}
	printf("Message received : %s", buffer);
	close(pipefd[0]);
	}
	return 0;
}	
