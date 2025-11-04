#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char *args[] = {"/bin/ls", NULL};
  if ((execve("/bin/ls", args, NULL)) == -1) {
    perror("execve failed");
    exit(EXIT_FAILURE);
  }

  puts("I should not be here!");
  exit(EXIT_SUCCESS);
}
