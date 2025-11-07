#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_sigset_t.h>
#include <sys/signal.h>

int main() {
  int ret;
  // Creates a new signal set
  sigset_t my_set;

  // initializes the signal set so is empty
  ret = sigemptyset(&my_set);
  if (ret < 0) {
    perror("no idea what happened, couldn't initialize the signal set");
    return EXIT_FAILURE;
  }

  // Add a new signal to the set, when a child terminates
  ret = sigaddset(&my_set, SIGCHLD);
  if (ret < 0) {
    perror("no idea why it failed when adding the signal");
    return EXIT_FAILURE;
  }

  // Check if we have the signal in our signal set
  if (sigismember(&my_set, SIGCHLD)) {
    puts("We have a signal for child termination");
  } else {
    perror("Somehow we don't?");
    return EXIT_FAILURE;
  }

  if (sigismember(&my_set, SIGTERM)) {
    perror("Who puts SIGTERM here?");
    return EXIT_FAILURE;
  } else {
    puts("As expected, SIGTERM is not here");
  }

  return EXIT_SUCCESS;
}
