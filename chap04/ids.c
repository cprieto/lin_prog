#include <stdio.h>
#include <unistd.h>

int main() {
  printf("Real User ID: %d\n", getuid());
  printf("Effective User ID: %d\n", getegid());
  printf("Real User Group ID: %d\n", getgid());
  printf("Effective User Group ID: %d\n", getegid());
}
