#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();

    if (pid1 < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid1 == 0) {
        printf("First child process: Executing 'ls' command\n");
        execl("/bin/ls", "ls", NULL);

        // If execl fails, print an error message
        perror("execl failed");
        exit(1);
    } else {
        pid2 = fork();

        if (pid2 < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid2 == 0) {
            printf("Second child process: Executing 'date' command\n");
            execl("/bin/date", "date", NULL);

            perror("execl failed");
            exit(1);
        } else {
            printf("Parent process: Child processes created with PIDs %d and %d\n", pid1, pid2);
           
            wait(NULL);  
            wait(NULL);  
            printf("Parent process done\n");
        }
    }

    return 0;
}