#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t child;
  int status;

  if ((child = fork()) < 0) {
    perror("fork failed");
    exit(EXIT_FAILURE);
  } else if (child == 0) {
    puts("I am child!");
    sleep(1000);
    exit(EXIT_SUCCESS);
  }

  if (waitpid(child, &status, WNOHANG) == 0) {
    int retval = kill(child, SIGKILL);
    if (retval) {
      puts("kill failed\n");
      perror("kill");
      waitpid(child, &status, 0);
    } else {
      printf("%d killed\n", child);
    }
  }

  exit(EXIT_SUCCESS);
}
