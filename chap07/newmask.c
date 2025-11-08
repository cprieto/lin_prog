#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
  // File will be created with current mask 022
  system("touch foo");
  mode_t newmask = 0666;
  mode_t oldmask = umask(newmask);

  printf("old mask is %#o\n", oldmask);
  printf("new mask is %#o\n", newmask);

  // file will be created with mask 0666
  // usually this is just a file with no permissions
  system("touch bar");
  return EXIT_SUCCESS;
}
