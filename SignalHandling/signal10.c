#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

// step1: implement signal handler
void sig_handler(int sig) {
    printf("SIGNAL caught: %d (PID=%d)\n", sig, getpid());
}

int main() {
    struct sigaction sa;
    int i=1, ret;
    sigset_t s;

    // step2: register signal handler using sigaction()
    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_handler = sig_handler;
    ret = sigaction(SIGINT, &sa, NULL);
    if(ret < 0) {
        perror("sigaction() failed");
        _exit(1);
    }
    ret = sigaction(SIGTERM, &sa, NULL);
    if(ret < 0) {
        perror("sigaction() failed");
        _exit(1);
    }

    printf("Wait for any signal...\n");
    pause(); // same as suspend() for any signal
        // save old sig mask in a temp var
        // set the "all sig allowed" mask to process's sig mask field
        // put process in waiting state (until any one signal is received)
        // restore old sig mask field (again in process sig mask field)
    
    printf("Bye!\n");
    return 0;
}