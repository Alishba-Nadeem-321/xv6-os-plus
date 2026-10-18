#include "kernel/types.h"
#include "user/user.h"

#define ITERATIONS 10000

int
main(void)
{
  volatile uint64 add_result = 0;
  volatile uint64 mul_result = 1;
  uint64 start, end;
  uint64 add_cycles, mul_cycles;
  int i;

  printf("Instruction-Level Arithmetic Benchmark\n");
  printf("Iterations: %d\n", ITERATIONS);

  // Addition benchmark
  start = getcycle();

  for (i = 0; i < ITERATIONS; i++) {
    add_result = add_result + i;
  }

  end = getcycle();
  add_cycles = end - start;

  // Multiplication benchmark
  start = getcycle();

  for (i = 0; i < ITERATIONS; i++) {
    mul_result = mul_result * 3 + i;
  }

  end = getcycle();
  mul_cycles = end - start;

  printf("Addition result: %d\n", (int)add_result);
  printf("Addition cycles: %d\n", (int)add_cycles);
  printf("Multiplication result: %d\n", (int)mul_result);
  printf("Multiplication cycles: %d\n", (int)mul_cycles);

  exit(0);
}
