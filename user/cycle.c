#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  uint64 start, end;
  volatile int i;

  printf("RISC-V CPU Cycle Reader\n");

  start = getcycle();

  for(i = 0; i < 10000; i++)
    ;

  end = getcycle();

  printf("Start cycles: %ld\n", start);
  printf("End cycles: %ld\n", end);
  printf("Cycles used: %ld\n", end - start);

  exit(0);
}
