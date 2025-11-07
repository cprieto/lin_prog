#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int);

int main() {
  struct sigaction action;

  action.sa_handler = handler;
  action.sa_flags = SA_NOCLDSTOP;
  sigemptyset(&action.sa_mask);

  // Now is time to register the signal
  sigaction(SIGUSR1, &action, NULL);

  printf("pid %d waiting for SIGUSR1\n", getpid());
  sleep(60);

  return EXIT_SUCCESS;
}

void handler(int signum) {
  if (signum == SIGUSR1)
    printf("got signal %d\n", signum);
}
