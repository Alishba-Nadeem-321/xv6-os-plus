#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  uint64 start, end;

  start = getcycle();
  end = getcycle();

  printf("RISC-V CPU Cycle Reader\n");
  printf("First reading:  %ld\n", start);
  printf("Second reading: %ld\n", end);
  printf("Cycles between readings: %ld\n", end - start);

  exit(0);
}
