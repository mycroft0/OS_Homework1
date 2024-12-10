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
        
        execl("/usr/bin/grep", "grep", "main", "text.txt", NULL);

        perror("execl failed");
        exit(1);
    } else {
    
        wait(NULL);
        printf("Parent process completed\n");
    }

    return 0;
}