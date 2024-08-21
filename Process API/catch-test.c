#include "signal.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

void handler(int sig) {
    printf("signal %d was caught \n", sig);
    exit(1);
    return;
}

int volatile done;

void anotherhandler(int sig, siginfo_t *siginfo, void *context) {
    printf("signal %d was caught \n", sig);
    printf("your UID is %d\n", siginfo->si_uid);
    printf("your PID is %d\n", siginfo->si_pid);
    done = 1;
}

int main() {
    struct sigaction sa;
    int pid = getpid();
    printf("Ok, let's go kill me (%d).\n", pid);
    /* we're using the more elaborated sigaction handler */
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = anotherhandler;/* INSERT HERE */
            sigemptyset(&sa.sa_mask);
    if (sigaction(SIGINT/* INSERT HERE */, &sa, NULL) != 0) {
        return (1);
    }
    while (!done) {
    }
    printf("Told you so! \n");
    return (0);
}
