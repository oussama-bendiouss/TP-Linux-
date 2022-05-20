#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_RED "\x1b[31m"
#define COLOR_RESET "\x1b[0m"
#define BMAG "\033[0;35m"
// works fine
// looks like working fine
int usage(char *pn) {
  printf("Usage : %s [OPTION] [STRING] ... [FILE]\n", pn);
  printf("Can be used look for specific strings in a file or many files.\n\n");
  printf("   -v  inverse match\n");
  printf("   -i  ignore case\n");
  printf("   -h  display this help and exit\n");
  printf("   -r  display this help and exit\n\n");
  printf("Examples\n");
  printf("  %s -i yaaay file.txt  looks for occurences of yaaaay in file.txt "
         "while ignoring the case\n",
         pn);
  return 0;
}

int version() {
  puts("TP : Programmation Linux Windows, CentraleSupélec, 2022 \u00A9\ngrep "
       "program : basic functionnality works fine with some few features");
  return 0;
}

void grep(char *s, char *f, int i, int v, int number_of_files) {
  FILE *fp = NULL;
  char line[100];
  char *s_copy = malloc(sizeof(s));
  strcpy(s_copy, s);
  for (int i = 0; s_copy[i]; i++) {
    s_copy[i] = tolower(s_copy[i]);
  }
  fp = fopen(f, "r");
  if (f == NULL) {
    perror("Failed: ");
    return;
  }
  if (i && v) {
    while (fscanf(fp, "%[^\n]\n", line) != EOF) {
      for (int i = 0; line[i]; i++) {
        line[i] = tolower(line[i]);
      }
      if (strstr(line, s_copy) != NULL) {
        continue;
      } else {
        if (number_of_files == 2)
          printf("%s\n", line);
        else
          printf("%s%s%s : %s\n", BMAG, f, COLOR_RESET, line);
      }
    }
  } else if (i) {
    while (fscanf(fp, "%[^\n]\n", line) != EOF) {
      char *line_copy = malloc(sizeof(char) * 101);
      strcpy(line_copy, line);
      for (int i = 0; line_copy[i]; i++) {
        line_copy[i] = tolower(line_copy[i]);
      }
      if (strstr(line_copy, s_copy) != NULL) {
        if (number_of_files == 2) {
          char *head_copy = line_copy;
          char *color_start_copy = strstr(line_copy, s_copy);
          int counter = 0;
          while (head_copy != color_start_copy) {
            head_copy++;
            counter++;
          }
          char *head = line;
          char *color_start = head + counter;
          char *color_end = color_start + strlen(s);
          while (*head) {
            if (head == color_start) {
              printf("%s", COLOR_RED);
            } else if (head == color_end) {
              printf("%s", COLOR_RESET);
            }
            putchar(*head++);
          }
          printf("%s\n", COLOR_RESET);
        } else {
          char *head_copy = line_copy;
          char *color_start_copy = strstr(line_copy, s_copy);
          int counter = 0;
          while (head_copy != color_start_copy) {
            head_copy++;
            counter++;
          }
          char *head = line;
          char *color_start = head + counter;
          char *color_end = color_start + strlen(s);
          printf("%s%s%s : ", BMAG, f, COLOR_RESET);
          while (*head) {
            if (head == color_start) {
              printf("%s", COLOR_RED);
            } else if (head == color_end) {
              printf("%s", COLOR_RESET);
            }
            putchar(*head++);
          }
          printf("%s\n", COLOR_RESET);
        }
      } else {
        continue;
      }
    }
  } else if (v) {
    while (fscanf(fp, "%[^\n]\n", line) != EOF) {
      if (strstr(line, s) != NULL) {
        continue;
      } else {
        if (number_of_files == 2)
          printf("%s\n", line);
        else
          printf("%s%s%s : %s\n", BMAG, f, COLOR_RESET, line);
      }
    }
  } else {
    while (fscanf(fp, "%[^\n]\n", line) != EOF) {
      if (strstr(line, s) != NULL) {
        if (number_of_files == 1) {
          char *head = line;
          char *color_start = strstr(line, s);
          char *color_end = color_start + strlen(s);
          while (*head) {
            if (head == color_start) {
              printf("%s", COLOR_RED);
            } else if (head == color_end) {
              printf("%s", COLOR_RESET);
            }
            putchar(*head++);
          }
          printf("%s\n", COLOR_RESET);
        } else {
          char *head = line;
          char *color_start = strstr(line, s);
          char *color_end = color_start + strlen(s);
          printf("%s%s%s : ", BMAG, f, COLOR_RESET);
          while (*head) {
            if (head == color_start) {
              printf("%s", COLOR_RED);
            } else if (head == color_end) {
              printf("%s", COLOR_RESET);
            }
            putchar(*head++);
          }
          printf("%s\n", COLOR_RESET);
        }
      } else {
        continue;
      }
    }
  }
  fclose(fp);
}

int main(int argc, char *argv[]) {

  int v = 0;
  int i = 0;
  int option = 0;
  int h = 0;
  int r = 0;

  if (argv[1][0] == '-') {
    argv[1]++;
    while (*argv[1]) {
      if (argv[1][0] == 'v') {
        v = 1;
        option = 1;
      } else if (argv[1][0] == 'i') {
        i = 1;
        option = 1;
      } else if (argv[1][0] == 'h') {
        h = 1;
        usage(argv[0]);
      } else if (argv[1][0] == 'r') {
        r = 1;
        version();
      } else {
        printf("Error : the %c is option not available use -h to see the help "
               "menu\n",
               argv[1][0]);
        return 0;
      }
      argv[1]++;
    }
  } 
  if ((argc == 2 && !(h || r)) || (argc == 3 && option)) {
    printf("%sPlease provide all necessary elements%s\n", COLOR_RED,COLOR_RESET);
    usage(argv[0]);
  }
  
  if (!h && !r){
    for (int j = 2+(i | v); j < argc; j++) {
      grep(argv[1+(i | v)], argv[j], i, v, argc - 2);
    }
  }

  return 0;
}