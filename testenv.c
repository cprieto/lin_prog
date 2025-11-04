#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char envval[] = {"MYPATH=/Users/cprieto"};
  if (putenv(envval))
    puts("putenv failed");
  else
    puts("putenv succeeded");

  if (getenv("MYPATH"))
    printf("YOUROATH=%s\n", getenv("MYPATH"));
  else
    puts("YOURPATH unassigned");

  exit(EXIT_SUCCESS);
}
