#include<stdio.h>
#include<string.h>
void fn(char *a)
{
char buf[10];
strcpy(buf,a);
printf("function fn finishes\n");
}

int main(int argc, char *argv[])

{
fn(argv[1]);
printf("finished\n");
return 0;
}
