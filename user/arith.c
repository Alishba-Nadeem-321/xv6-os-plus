#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  int a = 12;
  int b = 8;
  int result = add(a, b);

  printf("Kernel Arithmetic System Call\n");
  printf("%d + %d = %d\n", a, b, result);

  exit(0);
}
