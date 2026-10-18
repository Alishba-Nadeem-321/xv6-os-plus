#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int
main(void)
{
  struct fileop_stats stats;
  char buf[32];

  int fd = open("README.md", O_RDONLY);
  if(fd >= 0) {
    read(fd, buf, sizeof(buf));
    close(fd);
  }

  if(fileopinfo(&stats) < 0) {
    printf("File operation statistics failed\n");
    exit(1);
  }

  printf("File Operation Usage Monitor\n");
  printf("Open calls: %d\n", stats.open_count);
  printf("Read calls: %d\n", stats.read_count);
  printf("Write calls: %d\n", stats.write_count);
  printf("Close calls: %d\n", stats.close_count);

  exit(0);
}
