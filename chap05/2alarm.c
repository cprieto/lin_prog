#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  long int ret;

  // Setting an alarm that will kill us anyway
  ret = alarm(15);
  if (ret > 0) {
    perror("weird, first alarm is already set!");
    return EXIT_FAILURE;
  }

  sleep(3);
  // Set a second alarm, it will cancel first
  // it returns how long was left for first alarm
  ret = alarm(5);
  if (ret > 0)
    printf("seconds left for first alarm: %ld\n", ret);

  sleep(2);
  // To cancel the alarm, just pass 0
  ret = alarm(0);
  printf("seconds left for second alarm: %ld\n", ret);

  return EXIT_FAILURE;
}
