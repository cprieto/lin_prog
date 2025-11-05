#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t child = fork();
  if (child == 0) {
    printf("Hi, I am child! (%d)\n", getpid());
    sleep(30);
  } else if (child < 0) {
    perror("uff, fork failed!");
    return EXIT_FAILURE;
  } else {
    sleep(5);
    char str[256];
    sprintf(str, "%d", child);
    printf("killing child %d\n", child);

    if ((execl("/bin/kill", "/bin/kill", str, NULL)) < 0) {
      perror("problem when calling kill");
      waitpid(child, NULL, 0);

      return EXIT_FAILURE;
    }

    // We did exec, nothing here happens!
  }

  return EXIT_FAILURE;
}
