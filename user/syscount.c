#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc,char*argv[])
{
if(argc != 2){
printf("Usage: syscount syscall_number\n");
exit(1);
}
int n = atoi(argv[1]);
printf("System call %d count : %d\n",n,getsyscount(n));
exit(0);
}
