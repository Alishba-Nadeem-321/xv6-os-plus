#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int
main(void)
{
  int fd;
  char buf[2];
  uint counts[4];

  fd = open("fileopinfo.tmp", O_CREATE | O_RDWR);
  if (fd < 0) {
    printf("fileopinfo: open failed\n");
    exit(1);
  }

  if (write(fd, "X", 1) != 1) {
    printf("fileopinfo: write failed\n");
    close(fd);
    exit(1);
  }
  close(fd);

  fd = open("fileopinfo.tmp", O_RDONLY);
  if (fd < 0) {
    printf("fileopinfo: reopen failed\n");
    exit(1);
  }

  if (read(fd, buf, 1) != 1) {
    printf("fileopinfo: read failed\n");
    close(fd);
    exit(1);
  }
  close(fd);

  if (fileopinfo(counts) < 0) {
    printf("fileopinfo: counter query failed\n");
    exit(1);
  }

  printf("File Operation Usage Monitor\n");
  printf("Open calls: %d\n", counts[0]);
  printf("Read calls: %d\n", counts[1]);
  printf("Write calls: %d\n", counts[2]);
  printf("Close calls: %d\n", counts[3]);

  unlink("fileopinfo.tmp");
  exit(0);
}