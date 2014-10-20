#include<stdio.h>
#include<string.h>
void fn(char *a) {
  char buf[10];
  strcpy(buf, a);
  printf("the end of fn\n");
}

int main (int argc, char *argv[]) {
  fn(argv[1]);
  printf("the end\n");
  return 0;
}
