#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t child = fork();

  if (child < 0) {
    perror("problem when forking");
    return EXIT_FAILURE;
  }

  if (child == 0) {
    printf("Hi, I am child %d\n", getpid());
    sleep(30);
    printf("nothing happened, exiting");
    return EXIT_SUCCESS;
  }

  sleep(5);
  printf("sending SIGCHLD to %d\n", child);
  int err = kill(child, SIGCHLD);
  if (err < 0) {
    perror("something happened while sending signal to child");
    return EXIT_FAILURE;
  }

  puts("child is still alive!");
  printf("Time to kill %d\n", child);

  err = kill(child, SIGTERM);
  if (err < 0) {
    perror("something happened while trying to murder child");
    return EXIT_FAILURE;
  }

  waitpid(child, NULL, 0);
  return EXIT_SUCCESS;
}
