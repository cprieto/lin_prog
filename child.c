#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  pid_t child;

  if ((child = fork()) == -1) {
    perror("problem when forking!");
    exit(EXIT_FAILURE);
  } else if (child == 0) {
    puts("in child process");
    printf("\tchild pid = %d\n", getpid());
    printf("\tchild ppid = %d\n", getppid());
    exit(EXIT_SUCCESS);
  } else {
    puts("In parent process");
    printf("\tparent pid = %d\n", getpid());
    printf("\tparent ppid = %d\n", getppid());
    exit(EXIT_SUCCESS);
  }
}
