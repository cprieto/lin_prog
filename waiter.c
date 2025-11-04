#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t child;
  int status;

  if ((child = fork()) == -1) {
    perror("problem while forking");
    exit(EXIT_FAILURE);
  } else if (child == 0) {
    puts("in child");
    printf("\tchild pid: %d\n", getpid());
    printf("\tchild parent id: %d\n", getppid());
    exit(EXIT_SUCCESS);
  }

  waitpid(child, &status, 0);
  puts("in parent");
  printf("\tparent id: %d\n", getpid());
  printf("\tsuper parent id: %d\n", getppid());
  printf("\tchild exited with status %d\n", status);

  exit(EXIT_SUCCESS);
}
