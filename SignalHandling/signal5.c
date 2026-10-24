#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

void sigchld_handler(int sig) {
    int s;
    // get exit status of child
    waitpid(-1, &s, 0);
    printf("child exit status: %d\n", WEXITSTATUS(s));
}

int main() {
    int ret, i, s;
    struct sigaction sa, saold;
    // UNIX syscall = signal()
    //signal(SIGCHLD, sigchld_handler);

    // LINUX syscall = sigaction()
    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_handler = sigchld_handler;
    ret = sigaction(SIGCHLD, &sa, &saold);
    if(ret < 0) {
        perror("sigaction() failed");
        _exit(1);
    }
    
    ret = fork();
    if(ret == 0) { // child
        for(i=1; i<=5; i++) {
            printf("child: %d\n", i);
            sleep(1);
        }
        //_exit(0);
        _exit(5);
    }
    else { // parent
        for(i=1; i<=10; i++) {
            printf("parent: %d\n", i);
            sleep(1);
        }
    }
    return 0;
}
