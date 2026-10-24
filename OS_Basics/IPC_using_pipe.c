#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    char buffer[30];
    if (pipe(pipefd) == -1) {
        perror("Pipe generation failed");
        return 1;
    }
    if (fork() == 0) {
        close(pipefd[1]); // Close unused write end
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child read from pipe: %s\n", buffer);
        close(pipefd[0]);
    } else {
        close(pipefd[0]); // Close unused read end
        char *msg = "IPC Signal Received";
        write(pipefd[1], msg, strlen(msg) + 1);
        close(pipefd[1]);
    }
    return 0;
}
