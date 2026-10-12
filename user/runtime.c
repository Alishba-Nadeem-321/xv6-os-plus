#include "kernel/types.h"
#include "user/user.h"
int
main(void)
{
 int i;
 int start,end;
 start = getruntime();
 for (i = 0;i< 10000000; i++){
   // Busy loop to let timer ticks accumulate.
}
 end = getruntime();

 printf("Process Runtime Tracker\n");
 printf("Start ticks: %d\n", start);
 printf("End ticks: %d\n", end);
 printf("Runtime ticks used: %d\n", end - start);

 exit(0);
}
