/**********************************************************
 * dump.c.c
 * This file outputs our memory dump in a nice table format
 * Author: Nick Palumbo
 *   Date Created: February 1, 2016
 *   Last Modified by: Nick Palumbo
 *   Date Last Modified: February 5, 2016
 *   Assignment: Lab 3
 *   Part of: poly
 */

#include <stdio.h>

void dump_memory(void *p, int len)
{
  int i;
  
  printf("address %9s hexCh short %11s %13s %16s\n","char","integer","float","doubleFloat");
  for (i = 0; i < len; i++) {
    
    //address
    printf("%8p: ",p + i);
    
    //char
    if(*(char *)(p + i) > 127 || *(char *)(p + i) < 32)
      printf("? ");
    else
      printf("%c ",*(char *)(p + i));
    
    // hexCh
    if(*(unsigned char *)(p + i))
      printf("%#04x ",*(unsigned char *)(p + i));
    else
      printf("0x00 ");
    
    // short
    if(i % 2 == 0)
      printf("%+6d ",*(unsigned short *)(p + i));
    else
      printf("%6c ",' ');
    
    // integer
    if(i % 4 == 0)
      printf("%+11d ",*(int *)(p + i));
    else
      printf("%11c ",' ');
    
    // float
    if(i % 4 == 0)
      printf("%+1.6e ", *(float *)(p + i));
    else
       printf("%12c ", ' ');
  
    // doubleFloat
    if(i % 8 == 0)
      printf(" %+15.6e\n",*(double *)(p + i));
    else
      printf("\n");
  }
}
