#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        printf("Child process: Executing 'ls' command\n");

        execl("/bin/ls", "ls", NULL);

        perror("execl failed");
        exit(1);
    } else {
        printf("Parent process: Child created with PID %d\n", pid);

        wait(NULL);
        printf("Parent process done\n");
    }

    return 0;
}