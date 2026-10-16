#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  int numbers[4];
  char *base;
  uint64 address;
  int i;

  printf("Memory Alignment Demonstrator\n");
  printf("-----------------------------\n");

  base = (char *)numbers;

  printf("Array base address: %p\n", base);

  for (i = 0; i < 4; i++) {
    address = (uint64)&numbers[i];

    printf("Element %d address: %p\n", i, &numbers[i]);
    printf("  Address mod 4 = %d\n", (int)(address % 4));
    printf("  Address mod 8 = %d\n", (int)(address % 8));

    if (address % 4 == 0)
      printf("  4-byte aligned: YES\n");
    else
      printf("  4-byte aligned: NO\n");

    if (address % 8 == 0)
      printf("  8-byte aligned: YES\n");
    else
      printf("  8-byte aligned: NO\n");
  }

  exit(0);
}

