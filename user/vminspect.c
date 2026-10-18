#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  printf("Page Table Inspector\n");
  printf("Inspecting the current process page table...\n");

  if (vminspect() < 0) {
    printf("Page table inspection failed.\n");
    exit(1);
  }

  printf("Page table inspection completed.\n");
  exit(0);
}
