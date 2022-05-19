
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BMAG "\033[0;35m"
#define COLOR_RESET "\e[0m"

// works fine 
// Looks like finished

void cat(int argc, char *argv[],int n) {
  FILE *file;
  int chr;
  int count;
  int line_number;

  for (count = 1+n; count < argc; count++) {
    line_number = 1;
    if ((file = fopen(argv[count], "r")) == NULL) {
      fprintf(stderr, "%s: %s : %s\n", argv[0], argv[count], strerror(errno));
      continue;
    }
    if ((argc >= 3 && !n) || (argc>=4 && n)) printf("%s%s%s\n",BMAG,argv[count],COLOR_RESET);
    if (n) printf("1 : ");
    while ((chr = getc(file)) != EOF){
      fprintf(stdout, "%c", chr);
      if (chr == '\n' && n) {
        line_number++;
        printf("%d : ",line_number);
      }
    }
    if (n) printf("\n");
    fclose(file);
  }
}

void version(){
  puts("TP : Programmation Linux Windows, CentraleSupélec, 2022 \u00A9\nCat program : basic functionnality works fine with some few features");
}

void usage(char* pn){
  printf("Usage : %s [OPTION] ... [FILE] ...\n",pn);
  printf("Can be used to concatenate FILES to standard output.\n\n");
  printf("   -v  show version\n");
  printf("   -n  number all output lines\n");
  printf("   -h  display this help and exit\n\n");
  printf("Examples\n");
  printf("  %s -n file     Output file content and number output lines\n",pn);
}

int main(int argc, char *argv[]) { 

  int n = 0;

  if (argv[1][0]=='-'){
    char * p = argv[1];
    while (*p){
      switch (*p){
        case 'n' : n=1; cat(argc,argv++,n); break;
        case 'v' : version(); break;
        case 'h' : usage(argv[0]); break;
      }
      p++;
    }
  } else {
    cat(argc,argv,0);
  }
  exit(0); 
}