#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// step 1: implement signal handler fn
// programmer may implement common handler for multiple signals
void my_sig_handler(int sig) {
    if(sig == SIGINT)
        printf("SIGINT caught: %d\n", sig);
    else if(sig == SIGTERM)
        printf("SIGTERM caught: %d\n", sig);
    else
        printf("SIG caught: %d\n", sig);
}

void sigsegv_handler(int sig) {
    printf("SIGSEGV caught: %d\n", sig);
    _exit(0);
}

int main() {
    int i = 1;
    // register signal handler fn
    signal(SIGINT, my_sig_handler);
    signal(SIGTERM, my_sig_handler);
    signal(SIGALRM, my_sig_handler);
    signal(SIGSEGV, sigsegv_handler);

    while(1) {
        printf("running: %d\n", i);
        i++;
        sleep(1);
    }
    return 0;
}
