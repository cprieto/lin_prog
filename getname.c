#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>

int main() {
  char* login;
  struct passwd* pentry;

  // Get login name
  if ((login = getlogin()) == NULL) {
    perror("error while getting current user login name");
    exit(EXIT_FAILURE);
  }
  printf("current login user: %s\n", login);

  // Get more data about the user
  if ((pentry = getpwnam(login)) == NULL) {
    perror("error while getting current user data");
    exit(EXIT_FAILURE);
  }

  // Show the full name from gecos
  printf("GECOS: %s\n", pentry->pw_gecos);
}
