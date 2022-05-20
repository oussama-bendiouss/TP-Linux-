#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
//works fine
int main(int argc, char **argv) {
  if (argc > 1) {
    fprintf(stderr, "usage: whoami\n");
    return 1;
  }

  struct passwd *pw;
  char *user = NULL;

  pw = getpwuid(geteuid());
  if (pw)
    user = pw->pw_name;
  else if ((user = getenv("USER")) == NULL) {
    fprintf(stderr, "No user in the environemnt !\n");
    return 1;
  }
  printf("%s\n", user);
  return 0;
  
}
