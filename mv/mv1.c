#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
// don't really work yet
    // check if it is the same inode on the same device
#define SAME_INODE(a, b) ((a).st_ino == (b).st_ino && (a).st_dev == (b).st_dev)

    // ALL CHECKS OMMITTED!

int main(int argc, char **argv)
{

  struct stat statbuf_src, statbuf_dest;
  char *src, *dest, *new_src, *new_dest;
  char *current_directory;

  if (argc != 3) {
    fprintf(stderr, "usage: %s src dest\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  // work on copy
  src = malloc(strlen(argv[1]) + 1);
  dest = malloc(strlen(argv[2]) + 1);
  strcpy(src, argv[1]);
  strcpy(dest, argv[2]);

  stat(src, &statbuf_src);
  stat(dest, &statbuf_dest);

  // there are many more, of course
  /* printf("\"%s\" is a ", src);
  if (S_ISREG(statbuf_src.st_mode)) {
    puts("a regular file");
  }
  if (S_ISDIR(statbuf_src.st_mode)) {
    puts("a directory");
  }

  printf("\"%s\" is a ", dest);
  if (S_ISREG(statbuf_dest.st_mode)) {
    puts("a regular file");
  }
  if (S_ISDIR(statbuf_dest.st_mode)) {
    puts("a directory");
  } */

  /* if (SAME_INODE(statbuf_dest, statbuf_src)) {
    printf("%s and %s are the identical\n", src, dest);
    return 0;
  } */
  // if that is not set you have to do it by hand:
  // climb up the tree, concatenating names until the inodes are the same
  current_directory = getenv("PWD");
  //printf("current directory is \"%s\"\n", current_directory);

  new_src = malloc(strlen(src) + 1 + strlen(current_directory) + 1);
  strcpy(new_src,current_directory);
  strcat(new_src,"/");
  strcat(new_src,src);
  //printf("new_src = %s\n",new_src);

  new_dest = malloc(strlen(dest) + 1 + strlen(current_directory) + 1 + strlen(src) + 1);
  strcpy(new_dest,current_directory);
  strcat(new_dest,"/");
  strcat(new_dest,dest);
  strcat(new_dest,"/");
  strcat(new_dest,src);
  //printf("new_dest = %s\n",new_dest);

  if(rename(new_src,new_dest) != 0){
    fprintf(stderr,"rename failed : %s\n",strerror(errno));
  }

  free(new_src);
  free(new_dest);
  free(src);
  free(dest);

  exit(EXIT_SUCCESS);
}