#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int ret;
  sigset_t my_signals;

  // We can get ALL signals in one call
  ret = sigfillset(&my_signals);
  if (ret < 0) {
    perror("Somehow I cannot create this set");
    return EXIT_FAILURE;
  }

  // Let's remove SIGALARM
  ret = sigdelset(&my_signals, SIGCHLD);
  if (ret < 0) {
    perror("Oops, problem while removing a signal");
    return EXIT_FAILURE;
  }

  // Let's check is there
  if (!sigismember(&my_signals, SIGCHLD)) {
    puts("SIGCHLD is not in my set");
  }

  // Let's check if is there again
  if (sigismember(&my_signals, SIGTERM)) {
    puts("As expected, SIGTERM is there");
  }

  return EXIT_SUCCESS;
}
