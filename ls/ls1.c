#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
//dont work
int main(int argc, char **argv) {
  struct dirent **namelist;
  int n;
  if (argc < 1) {
    fprintf(stderr,"usage : ls directory");
    //exit(EXIT_FAILURE);
    return 0;
  } else if (argc == 1) {
    n = scandir(".", &namelist, NULL, alphasort);
  } else {
    n = scandir(argv[1], &namelist, NULL, alphasort);
  }
  if (n < 0) {
    perror("scandir");
    //exit(EXIT_FAILURE);
    return 0;
  } else {
    while (n) {
      printf("%s \n", namelist[n]->d_name);
      //free(namelist[n]);
    }
    //free(namelist);
  }
  //exit(EXIT_SUCCESS);
  return 0;
}
