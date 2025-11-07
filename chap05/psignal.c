#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  sigset_t my_signals;
  sigemptyset(&my_signals);

  // We will block some signals
  sigaddset(&my_signals, SIGALRM);
  sigaddset(&my_signals, SIGTERM);

  // For those signals, we pause them
  // This will set the signals for the process
  sigprocmask(SIG_BLOCK, &my_signals, NULL);

  printf("Waiting for something to happen (PID %d)\n", getpid());

  // Wait until something happen
  pause();

  printf("Something happened?\n");

  return EXIT_SUCCESS;
}
