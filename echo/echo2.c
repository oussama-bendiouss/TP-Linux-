#include <stdio.h>
#include <string.h>
//works fine
// Looks lie finished
void usage(char* pn){
  printf("Usage : %s [OPTION] [STRING]\n",pn);
  printf("Can be used to output to standard output.\n\n");
  printf("   -v  show version\n");
  printf("   -n  do not output trailing line\n");
  printf("   -h  display this help and exit\n\n");
  printf("Examples\n");
  printf("  %s string     Output file content and number output lines\n",pn);
}

void version(){
  puts("TP : Programmation Linux Windows, CentraleSupélec, 2022 \u00A9\nEcho program : basic functionnality works fine with some few features");
}

int
main(int argc, char *argv[])
{
  int n;
  if (argv[1][0]=='-'){
    char * p = argv[1];
    while (*p){
      switch (*p){
        case 'n' : n=1; break;
        case 'v' : n=1; version(); break;
        case 'h' : n=1; usage(argv[0]); break;
      }
      p++;
    }
  }

  for(int i = 1+n; i < argc; i++){
    fprintf(stdout, argv[i], strlen(argv[i]));
    if(i + 1 < argc){
      fprintf(stdout, " ");
    } else {
      if(!n) fprintf(stdout, "\n");
    }
  }
  return 0;
}