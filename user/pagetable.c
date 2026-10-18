#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  pagetable();
  exit(0);
}
