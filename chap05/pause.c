#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  // We wait for a signal, ANY signal
  pause();

  puts("time to go!");
  return EXIT_SUCCESS;
}
