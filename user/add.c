#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int a = 10;
  int b = 20;
  int result;

  result = add(a, b);

  printf("Kernel Arithmetic System Call\n");
  printf("First number: %d\n", a);
  printf("Second number: %d\n", b);
  printf("Sum: %d\n", result);

  exit(0);
}
