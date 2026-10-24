#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

// step1: implement signal handler
void sig_handler(int sig) {
    int i;
    for(i=1; i<=5; i++) {
        printf("SIGNAL caught: %d (PID=%d)\n", sig, getpid());
        sleep(1);
    }
}

int main() {
    struct sigaction sa;
    int i, ret;
    sigset_t s;

    // step2: register signal handler using sigaction()
    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_handler = sig_handler;
    sigfillset(&sa.sa_mask); // sig mask -- all signals masked -- to be used while execution of sig_handler()
    ret = sigaction(SIGINT, &sa, NULL);
    if(ret < 0) {
        perror("sigaction() failed");
        _exit(1);
    }

    for(i=1; ; i++) {
        printf("Running: %d\n", i);
        sleep(1);
    }

    return 0;
}