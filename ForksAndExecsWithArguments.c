#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid1;

    pid1 = fork();

    if (pid1 < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid1 == 0) {
        execl("/bin/echo", "echo", "Hello from the child process", NULL);
        
        perror("execl failed");
        exit(1);
    } else {
       wait(NULL);  // Wait for second child
       printf("Parent process done\n");
    }

    return 0;
}