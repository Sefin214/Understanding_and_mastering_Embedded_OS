#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

// step1: implement signal handler
// advanced signal handler -- receives detailed info about the signal
void sigint_handler(int sig, siginfo_t *si, void *param) {
    printf("SIGNAL caught: %d\n", sig);
    printf("Sender Process Id: %d\n", si->si_pid);
}

int main() {
    struct sigaction sa;
    int i=1, ret;
    // step2: register signal handler using sigaction()
    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_sigaction = sigint_handler;
    sa.sa_flags = SA_SIGINFO;
    ret = sigaction(SIGINT, &sa, NULL);
    if(ret < 0) {
        perror("sigaction() failed");
        _exit(1);
    }

    while(1) {
        printf("Running: %d\n", i++);
        sleep(1);
    }
    return 0;
}