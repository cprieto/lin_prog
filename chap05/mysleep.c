#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  if ((alarm(5)) > 0)
    puts("an alarm was already set");
  sleep(30);

  puts("We should never be here");
  return EXIT_FAILURE;
}
