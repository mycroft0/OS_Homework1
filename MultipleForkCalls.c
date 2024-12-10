#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    printf("Initial process: PID=%d\n", getpid());

    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    if (pid == 0) {
        printf("Child process 1: PID=%d, Parent PID=%d\n", getpid(), getppid());
    } else {
        printf("Parent process after 1st fork: PID=%d, Child PID=%d\n", getpid(), pid);
    }

    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    if (pid == 0) {
        printf("Child process 2: PID=%d, Parent PID=%d\n", getpid(), getppid());
    } else {
        printf("Parent process after 2nd fork: PID=%d, Child PID=%d\n", getpid(), pid);
    }

    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    if (pid == 0) {
        printf("Child process 3: PID=%d, Parent PID=%d\n", getpid(), getppid());
    } else {
        printf("Parent process after 3rd fork: PID=%d, Child PID=%d\n", getpid(), pid);
    }

    return 0;
}