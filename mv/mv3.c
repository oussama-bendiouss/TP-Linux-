#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc, char **argv) {
  if (argc > 3 || argc < 3) {
    printf("Please Provide two arugments \n");
  } else {
    int fd1, fd2;
    int n, count = 0;
    if (access(argv[1], F_OK) < 0) {
      printf("%s not found \n ", argv[1]);
    }
    if (rename(argv[1], argv[2]) == 0)
      printf(" %s is movied or renamed to %s \n successfully \n", argv[1],
             argv[2]);
    return (0);
  }
}