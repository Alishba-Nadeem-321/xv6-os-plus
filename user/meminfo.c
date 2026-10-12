#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
 int pages;

 pages = getmeminfo();

 printf("Physical Memory Usage Monitor\n");
 printf("Free pages: %d\n", pages);
 printf("Free memory: %d bytes\n", pages * 4096);

 exit(0);
}
