#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[100];
    const char *message = "Hello from the child process!";

    // 1. Create the pipe before calling fork()
    if (pipe(pipefd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    // 2. Create a child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // --- CHILD PROCESS (Sender) ---
		printf(" Inside Child : getpid() = %d, getppid()= %d\n", getpid(), getppid());
		getchar();
        // Close the unused read end to properly signal EOF when finished
        close(pipefd[0]); 

        printf("Child: Sending message to parent...\n");
        write(pipefd[1], message, strlen(message) + 1);
        
		getchar();
        // Close the write end after sending
        close(pipefd[1]); 
        exit(EXIT_SUCCESS);
    } else {
        // --- PARENT PROCESS (Receiver) ---
		printf(" Inside Parent : getpid() = %d, getppid()= %d\n", getpid(), getppid());
		getchar();
        // Close the unused write end so read() doesn't block indefinitely
        close(pipefd[1]); 

		getchar();
        // Read data sent by the child from the pipe
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Parent: Received message: \"%s\"\n", buffer);

        // Close the read end and clean up zombie process
        close(pipefd[0]);
        wait(NULL); 
    }
	sleep(15);
		getchar();
    return 0;
}

