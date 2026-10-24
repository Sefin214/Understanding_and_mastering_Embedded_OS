#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// step 1: implement signal handler fn
void sigint_handler(int sig) {
    printf("SIGINT caught: %d\n", sig);
}

void sigterm_handler(int sig) {
    printf("SIGTERM caught: %d\n", sig);
}

void sigsegv_handler(int sig) {
    printf("SIGSEGV caught: %d\n", sig);
    _exit(0);
}

int main() {
    int i = 1;
    // register signal handler fn
    signal(SIGINT, sigint_handler);
    signal(SIGTERM, sigterm_handler);
    signal(SIGSEGV, sigsegv_handler);

    while(1) {
        printf("running: %d\n", i);
        i++;
        sleep(1);
    }
    return 0;
}
