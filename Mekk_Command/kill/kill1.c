#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
// works fine
// works normally
struct Map {
  int signal;
  const char *sigstr;
};

int usage(char *pn) {
  printf("Usage : %s [OPTION] [PID]\n", pn);
  printf("Can be used look for specific strings in a file or many files.\n\n");
  printf("   -s SIGNAL[SIGSTOP, SIGKILL, ...] to send a specific signal to the "
         "process\n");
  printf("   -v  version\n");
  printf("   -h  display this help and exit\n");
  printf("Examples\n");
  printf("  %s -s SIGKILL 1250  kills the proc with pid 1250 "
         "while ignoring the case\n",
         pn);
  return 0;
}

int version() {
  puts("TP : Programmation Linux Windows, CentraleSupélec, 2022 \u00A9\nKill "
       "program : basic functionnality works fine with some few features");
  return 0;
}

int main(int argc, char **argv) {
  int length = 3;
  struct Map sigmap[length];
  sigmap[0].signal = SIGKILL;
  sigmap[0].sigstr = "SIGKILL";
  sigmap[1].signal = SIGSTOP;
  sigmap[1].sigstr = "SIGSTOP";
  sigmap[2].signal = SIGCONT;
  sigmap[2].sigstr = "SIGCONT";

  if (argc < 2) {
    printf("usage: ./kill PID\n");
    return -1;
  }
  int signal = SIGKILL;
  if (argv[1][0] == '-') {
    char *p = ++argv[1];
    switch (*p) {
    case 's': {
      char * sig = argv[2];
      for (int i = 0; i < length; i++) {
        if (!strcmp(sig, sigmap[i].sigstr)) {
          signal = sigmap[i].signal;
          break;
        }
      } 
      kill(atoi(argv[3]), signal);
      break;
    }
    case 'h' : usage(argv[0]); break;
    case 'v' : version(); break;
    default  : printf("The %c option is not correct, use -h to access the help menu",*p);
    }  
  }


return 0;
}