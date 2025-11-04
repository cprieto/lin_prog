#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/times.h>
#include <stdio.h>

void doit(char*, clock_t);

int main() {
  clock_t start, end;
  struct tms t_start, t_end;

  start = times(&t_start);
  system("grep the /usr/share/doc/*/* > /dev/null 2> /dev/null");
  end = times(&t_end);

  doit("elapsed", end - start);

  printf("parent times\n");
  doit("\tuser CPU: ", t_end.tms_utime);
  doit("\tsys CPU: ", t_end.tms_stime);

  printf("child times\n");
  doit("\tuser CPU: ", t_end.tms_cutime);
  doit("\tsys CPU: ", t_end.tms_cstime);
}

void doit(char* what, clock_t time) {
  long tps = sysconf(_SC_CLK_TCK);
  printf("%s: %6.2f secs\n", what, (float)time/tps);
}
