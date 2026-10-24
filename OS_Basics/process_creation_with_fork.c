#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork Failed");
        return 1;
    } else if (pid == 0) {
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        printf("Parent Process: PID = %d, Created Child PID = %d\n", getpid(), pid);
    }
    return 0;
}
