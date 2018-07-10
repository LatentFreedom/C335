#include <stdio.h>
#include "myprintf.c"

extern void myprintf(const char *, ...);

void printint(char x);
void printstring(char * x);
void printhex(char x);

int main(){
  myprintf("Nothing much\n");
  myprintf("The letter %c\n", 'A');
  myprintf("A string: %s\n", "Splash!");
  myprintf("The number %d\n", 11);
  myprintf("The number %x in hexadecimal\n", 11);
  myprintf("%d is a negative number\n", -5);
  myprintf("The number %d\n", 'A');
  myprintf("The number %x in hexadecimal\n", 'A');
}
