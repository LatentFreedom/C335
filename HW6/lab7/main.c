/********************************************************** 
* main.c
* This is the main file that gives output on the LCD screen given GYRO data
* Author: Nick Palumbo, Ethan Lawton
*   Date Created: April 12, 2016
*   Last Modified by: Nick Palumbo
*   Date Last Modified: April 12, 2016
*   Assignment: HW6
*   Part of: HW6
*/

#include "c335sim.h"
#include "screen.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <string.h>

#define EVENT_LOOP_TIME 200

int c335_main( int argc, char *argv[] ) {

  fillScreen(WHITE);
  
  FILE *inputFile;
  int i = 0; // counter
  char **coord; // hold x, y, z coordinates from file

  //uint16_t barColor, markerColor, baselineColor;
  
  // check if first arg is actually a file
  if(strstr(argv[2], ".txt")) { // if argv[1] contains string .txt
    inputFile = fopen(argv[2],"r"); // r for "read"
  } else {
    printf("File input not valid.\n");
    return 0;
  }

  // check if file could be opened
  if(inputFile == 0) {
    printf("Failed to open file.\n");
    return 0;
  }

  char line[13]; // string to hold a line read from input file
  char array[30][20]; // array of strings

  while (fgets(array[i], sizeof(line), inputFile)) {
    // remove the '\n' on the end of each string
    // fgets ends on '\n', buf size, or 'eof'
    array[i][11] = '\0';
    i++;
  }

  i = 0;
  char x[3],y[3],z[3];

  

  sscanf(array[0],"%s %s %s",x,y,z);

  drawChar(1,0,'X',BLACK,WHITE);
  drawString(10,0,x,BLACK,WHITE);

  drawChar(1,10,'Y',BLACK,WHITE);
  drawString(10,10,y,BLACK,WHITE);
  
  drawChar(1,20,'Z',BLACK,WHITE);
  drawString(10,20,z,BLACK,WHITE);
  
  int xi, yi, zi;
  
  xi = atoi(x);
  yi = atoi(y);
  zi = atoi(z);
  
  
  drawBars(RED, xi, yi, zi);

  while (1) {
    sscanf(array[i],"%s %s %s",x,y,z);
    xi = atoi(x);
    yi = atoi(y);
    zi = atoi(z);
    i = (i + 1) % 16; // increment i // % by amount of lines in file     
    event_loop(x,y,z,xi,yi,zi);
    Delay(EVENT_LOOP_TIME);
    }
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line) {
/* Infinite loop */
/* Use GDB to find out why we're here */
  while (1);
}
#endif

/* main.c ends here */
