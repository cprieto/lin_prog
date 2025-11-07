#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void handler(int);

int main() {
  sigset_t set, pending;
  struct sigaction action;

  action.sa_handler = handler;
  action.sa_flags = SA_NOCLDSTOP;
  sigemptyset(&action.sa_mask);
  sigaction(SIGUSR1, &action, NULL);
  printf("pid %d waiting for SIGUSR1\n", getpid());

  sigemptyset(&set);
  // I want to handle SIGTERM
  sigaddset(&set, SIGUSR1);
  // But we want to block it
  sigprocmask(SIG_BLOCK, &set, NULL);

  puts("SIGUSR1 is not going to be handled right now!");
  sleep(10);
  puts("Now SIGUSR1 is going to be handled!");

  return EXIT_SUCCESS;
}

void handler(int signum) { printf("Handling signal %d\n", signum); }
