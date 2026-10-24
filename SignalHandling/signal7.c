#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

// step1: implement signal handler
void sigint_handler(int sig) {
    printf("SIGNAL caught: %d (PID=%d)\n", sig, getpid());
}

int main() {
    struct sigaction sa;
    int i=1, ret;
    // step2: register signal handler using sigaction()
    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_handler = sigint_handler;
    ret = sigaction(SIGINT, &sa, NULL);
    if(ret < 0) {
        perror("sigaction() failed");
        _exit(1);
    }

    while(1) {
        printf("Running: %d (pid = %d)\n", i++, getpid());
        sleep(1);
    }
    return 0;
}