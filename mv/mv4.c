#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  int fd1, fd2, count;
  char buf[512];
  if (argc != 3) {
    printf("give sufficient filenames");
    exit(1);
  } else {
    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
      printf("source file does not exist");
      exit(1);
    }
    fd2 = open(argv[2], O_WRONLY);
    if (fd2 == -1)
      fd2 = creat(argv[2], 0666);
    while ((count = read(fd1, buf, 512)) > 0) {
      write(fd2, buf, count);
    }
    close(fd2);
    close(fd1);
  }
  int c = unlink(argv[1]);
  if (c == 0)
    printf("unlinked successfully");
  else
    printf("link error");
}