#include <stdio.h>

#define FILENAME "log.txt"
#define MAXLENGTHFILE 5000

char fileStr[MAXLENGTHFILE];

int fileToStr(char* str) {
  int status;
  FILE* fp = NULL;

  fp = fopen(FILENAME, "r");
  if (fp == NULL) {
    printf("File does not exist\n");
    return -1;
  }

  status = fread(str, MAXLENGTHFILE, 1, fp);

  printf("Noi dung cua file log.txt: \n%s", str);

  fclose(fp);
  fp = NULL;
  return status;
}

int main() {
  int buffer[MAXLENGTHFILE];
  int status = fileToStr(buffer);
  printf("test: %d \n", status);
  return 0;
}
