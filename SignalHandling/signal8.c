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
    sigset_t s;

    sigemptyset(&s); // 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
    sigaddset(&s, SIGTERM); // 00000000 00000010 00000000 00000000 00000000 00000000 00000000 00000000
    sigaddset(&s, SIGALRM); // 00000000 00000110 00000000 00000000 00000000 00000000 00000000 00000000
    ret = sigprocmask(SIG_SETMASK, &s, NULL);
    if(ret < 0) {
        perror("sigprocmask() failed");
        _exit(1);
    }

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