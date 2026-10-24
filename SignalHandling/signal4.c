#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void sigchld_handler(int sig) {
    int s;
    // get exit status of child
    waitpid(-1, &s, 0);
    printf("child exit status: %d\n", WEXITSTATUS(s));
}

int main() {
    int ret, i, s;
    signal(SIGCHLD, sigchld_handler);
    ret = fork();
    if(ret == 0) { // child
        for(i=1; i<=5; i++) {
            printf("child: %d\n", i);
            sleep(1);
        }
//        _exit(0);
        _exit(2);
    }
    else { // parent
        for(i=1; i<=10; i++) {
            printf("parent: %d\n", i);
            sleep(1);
        }
    }
    return 0;
}
