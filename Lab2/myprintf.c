#include <stdarg.h>
#include <stdio.h>

void printint(char x);
void printstring(char * x);
void printhex(char x);

void myprintf(const char *fmt, ...) {
  const char *p;
  va_list argp;
  int i;
  char *s;

  va_start(argp, fmt);

  for (p = fmt; *p != '\0'; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    switch (*++p) {
    case 'c':
      i = va_arg(argp, int);
      putchar(i);
      break;

    case 'd':
      i = va_arg(argp, int);
      printint(i);
      break;

    case 's':
      s = va_arg(argp, char *);
      printstring(s);
      break;

    case 'x':
      i = va_arg(argp, int);
      printhex(i);
      break;

    case '%':
      putchar('%');
      break;
    }
  }
  va_end(argp);
}

void printint(char n)
{
  if (n < 0) 
  {
    putchar('-');
    n = -n;
  }
  if (n == 0)
    putchar('0');

  if (n/10)
    printint(n/10);

  putchar(n%10 + '0');
}
void printstring(char * ch)
{
  while(*ch) {
     putchar(*ch);
     ch++;
  }
}
void printhex(char n)
{
  int quotient;
  int i=1,temp;
  char hexNum[100];
  quotient = n;

  while(quotient != 0) {
    temp = quotient % 16;
    if(temp < 10)
      temp = temp + '0'; 
    else
      temp += 55;
    hexNum[i++] = temp;
    quotient /= 16;
  }
  printstring(hexNum);
}