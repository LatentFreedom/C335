/********************************************************** 
* main.c
* This is main for Homework 3: disassembler program
* Author: Nick Palumbo
*   Date Created: February 28, 2016
*   Last Modified by: Nick Palumbo
*   Date Last Modified: March 2, 2016
*   Assignment: Homework 3
*   Part of: Homework 3
*/

  // Enter in up to 10 hex 4-digit numbers and they will output in thumb assembly form.
 // to stop ntering data and see an output, enter any key that is not considered hex. 
// I HAVE NO IDEA HOW THE BIT-SHIFTING WORKS! 										 


#include <stdio.h>
#include "hw3.h"
#include <string.h> // used for sprintf

#define Rm(x) (((x) >> 3) & 0x3)

char* gatherDataRegisters(int bits[16], char *regnames[9], char *registers[4]);

int main() {

	// lookup tables for register names and operation names
	char *regnames[]   = {"r0" ,"r1" ,"r2" ,"r3" ,"r4" ,"r5" ,"r6" ,"r7" ,"pc"};
	//                   { 000 , 001 , 010 , 011 , 100 , 101 , 110 , 111 }
	char *opnamesData[] = {"ands","eors","lsls","lsrs","asrs","adcs","sbcs","rors","tsts","rsbs","cmps","cmns","orrs","muls","bics","mvns"};
	//	                  {0000  ,0001  ,0010  ,0011  ,0100  ,0101  ,0110  ,0111  ,1000  ,1001  ,1010  ,1011  ,1100  ,1101  ,1110  ,1111  }
	char *opnamesAS[]	= {"adds","subs"};
	//					  { 0    , 1    }

	unsigned int inst;
	char *hexValue[5];
	unsigned int temp;

	int i;
	int counter = 0;    // counter for toPrint array
	int bits[16];       // array holding the hex input in binary
	char *registers[4]; // hold registers
	char *opname;       // hold the opname chosen

	// either data process registers or not
	int dataprocess = 0;
	int addSubRegisters = 0;

	// holds the strings to be printed
	char *toPrint[10];
	
	// accept one set hex values at a time and return the proper thumb assembly
	while (scanf("%x", &inst) == 1){
		temp = inst;

		// convert hex number into binary array
		for (i=15;i>=0;i--) {
  			bits[i]=inst&1;
  			inst>>=1;
		}

		if(!(bits[0] == 0 && bits[1] == 0 && bits[2] == 0 && bits[3] == 1 && bits[4] == 1 && bits[5] == 0) && !(bits[0] == 0 && bits[1] == 1 && bits[2] == 0 && bits[3] == 0 && bits[4] == 0 && bits[5] == 0)){
			opname = ".hword 0x"; // opname is bad data
			sprintf(&hexValue[0],"%d",temp); // convert input hex to string for output

			// convert data processing registers to one string
			char * str3 = (char *) malloc(1 + strlen(opname)+ 10);
			strcpy(str3, "   ");
      		strcat(str3, opname);
      		strcat(str3, &hexValue);

			toPrint[counter] = str3; // place the new string into the array of things to be printed
			counter++; // increment counter to hold the next string to be printed
		}

		// check for data-processing register
		else if(bits[0] == 0 && bits[1] == 1 && bits[2] == 0){
			if(bits[3] == 0 && bits[4] == 0 && bits[5] == 0){

				dataprocess = 1;

				// determine the opcode
				if(bits[6] == 0 && bits[7] == 0 && bits[8] == 0 && bits[9] == 0) // 0000 ands
					opname = opnamesData[0];
				if(bits[6] == 0 && bits[7] == 0 && bits[8] == 0 && bits[9] == 1) // 0001 eors
					opname = opnamesData[1];
				if(bits[6] == 0 && bits[7] == 0 && bits[8] == 1 && bits[9] == 0) // 0010 lsls
					opname = opnamesData[2];
				if(bits[6] == 0 && bits[7] == 0 && bits[8] == 1 && bits[9] == 1) // 0011 lsrs
					opname = opnamesData[3];
				if(bits[6] == 0 && bits[7] == 1 && bits[8] == 0 && bits[9] == 0) // 0100 asrs
					opname = opnamesData[4];
				if(bits[6] == 0 && bits[7] == 1 && bits[8] == 0 && bits[9] == 1) // 0101 adcs
					opname = opnamesData[5];
				if(bits[6] == 0 && bits[7] == 1 && bits[8] == 1 && bits[9] == 0) // 0110 sbcs
					opname = opnamesData[6];
				if(bits[6] == 0 && bits[7] == 1 && bits[8] == 1 && bits[9] == 1) // 0111 rors
					opname = opnamesData[7];
				if(bits[6] == 1 && bits[7] == 0 && bits[8] == 0 && bits[9] == 0) // 1000 tsts
					opname = opnamesData[8];
				if(bits[6] == 1 && bits[7] == 0 && bits[8] == 0 && bits[9] == 1) // 1001 rsbs
					opname = opnamesData[9];
				if(bits[6] == 1 && bits[7] == 0 && bits[8] == 1 && bits[9] == 0) // 1010 cmps
					opname = opnamesData[10];
				if(bits[6] == 1 && bits[7] == 0 && bits[8] == 1 && bits[9] == 1) // 1011 cmns
					opname = opnamesData[11];
				if(bits[6] == 1 && bits[7] == 1 && bits[8] == 0 && bits[9] == 0) // 1100 orrs
					opname = opnamesData[12];
				if(bits[6] == 1 && bits[7] == 1 && bits[8] == 0 && bits[9] == 1) // 1101 muls
					opname = opnamesData[13];
				if(bits[6] == 1 && bits[7] == 1 && bits[8] == 1 && bits[9] == 0) // 1110 bics
					opname = opnamesData[14];
				if(bits[6] == 1 && bits[7] == 1 && bits[8] == 1 && bits[9] == 1) //1111 mvns
					opname = opnamesData[15];
			}
		}

		// check for add/subtract register ops
		else if(bits[0] == 0 && bits[1] == 0 & bits[2] == 0) {
			if(bits[3] == 1 && bits[4] == 1 && bits[5] == 0){
				// set condition to 1 for add/sub registers
				addSubRegisters = 1;
				
				if(bits[6] == 0)
					opname = opnamesAS[0]; // 0 adds
				else
					opname = opnamesAS[1]; // 1 subs
			}
		}

		if(dataprocess == 1){
			// get first register used
			if(bits[10] == 0 && bits[11] == 0 & bits[12] == 0) /* */ registers[0] = regnames[0]; // 000
			if(bits[10] == 0 && bits[11] == 0 & bits[12] == 1) /* */ registers[0] = regnames[1]; // 001
			if(bits[10] == 0 && bits[11] == 1 & bits[12] == 0) /* */ registers[0] = regnames[2]; // 010
			if(bits[10] == 0 && bits[11] == 1 & bits[12] == 1) /* */ registers[0] = regnames[3]; // 011
			if(bits[10] == 1 && bits[11] == 0 & bits[12] == 0) /* */ registers[0] = regnames[4]; // 100
			if(bits[10] == 1 && bits[11] == 0 & bits[12] == 1) /* */ registers[0] = regnames[5]; // 101
			if(bits[10] == 1 && bits[11] == 1 & bits[12] == 0) /* */ registers[0] = regnames[6]; // 110
			if(bits[10] == 1 && bits[11] == 1 & bits[12] == 1) /* */ registers[0] = regnames[7]; // 111
				

			// get second register used
			if(bits[13] == 0 && bits[14] == 0 & bits[15] == 0) /* */ registers[1] = regnames[0]; // 000
			if(bits[13] == 0 && bits[14] == 0 & bits[15] == 1) /* */ registers[1] = regnames[1]; // 001
			if(bits[13] == 0 && bits[14] == 1 & bits[15] == 0) /* */ registers[1] = regnames[2]; // 010
			if(bits[13] == 0 && bits[14] == 1 & bits[15] == 1) /* */ registers[1] = regnames[3]; // 011
			if(bits[13] == 1 && bits[14] == 0 & bits[15] == 0) /* */ registers[1] = regnames[4]; // 100
			if(bits[13] == 1 && bits[14] == 0 & bits[15] == 1) /* */ registers[1] = regnames[5]; // 101
			if(bits[13] == 0 && bits[14] == 1 & bits[15] == 0) /* */ registers[1] = regnames[6]; // 110
			if(bits[13] == 1 && bits[14] == 1 & bits[15] == 1) /* */ registers[1] = regnames[7]; // 111

			// convert data processing registers to one string
			char * str3 = (char *) malloc(1 + strlen(opname)+ strlen(registers[1])+ strlen(registers[0])+ 4);
			strcpy(str3, "   ");
      		strcat(str3, opname);
      		strcat(str3, " ");
      		strcat(str3, registers[1]);
      		strcat(str3, ",");
      		strcat(str3, registers[0]);

			toPrint[counter] = str3; // place the new string into the array of things to be printed			
			counter++;       // increment counter to hold the next string to be printed
			dataprocess = 0; // finished so removing data process tag

		}
		if(addSubRegisters == 1){
			// get first register used
			if(bits[7] == 0 && bits[8] == 0 & bits[9] == 0) /* */ registers[0] = regnames[0]; // 000
			if(bits[7] == 0 && bits[8] == 0 & bits[9] == 1) /* */ registers[0] = regnames[1]; // 001
			if(bits[7] == 0 && bits[8] == 1 & bits[9] == 0) /* */ registers[0] = regnames[2]; // 010
			if(bits[7] == 0 && bits[8] == 1 & bits[9] == 1) /* */ registers[0] = regnames[3]; // 011
			if(bits[7] == 1 && bits[8] == 0 & bits[9] == 0) /* */ registers[0] = regnames[4]; // 100
			if(bits[7] == 1 && bits[8] == 0 & bits[9] == 1) /* */ registers[0] = regnames[5]; // 101
			if(bits[7] == 1 && bits[8] == 1 & bits[9] == 0) /* */ registers[0] = regnames[6]; // 110
			if(bits[7] == 1 && bits[8] == 1 & bits[9] == 1) /* */ registers[0] = regnames[7]; // 111

			// get second register used
			if(bits[10] == 0 && bits[11] == 0 & bits[12] == 0) /* */ registers[1] = regnames[0]; // 000
			if(bits[10] == 0 && bits[11] == 0 & bits[12] == 1) /* */ registers[1] = regnames[1]; // 001
			if(bits[10] == 0 && bits[11] == 1 & bits[12] == 0) /* */ registers[1] = regnames[2]; // 010
			if(bits[10] == 0 && bits[11] == 1 & bits[12] == 1) /* */ registers[1] = regnames[3]; // 011
			if(bits[10] == 1 && bits[11] == 0 & bits[12] == 0) /* */ registers[1] = regnames[4]; // 100
			if(bits[10] == 1 && bits[11] == 0 & bits[12] == 1) /* */ registers[1] = regnames[5]; // 101
			if(bits[10] == 0 && bits[11] == 1 & bits[12] == 0) /* */ registers[1] = regnames[6]; // 110
			if(bits[10] == 1 && bits[11] == 1 & bits[12] == 1) /* */ registers[1] = regnames[7]; // 111

			// get third register used
			if(bits[13] == 0 && bits[14] == 0 & bits[15] == 0) /* */ registers[2] = regnames[0]; // 000
			if(bits[13] == 0 && bits[14] == 0 & bits[15] == 1) /* */ registers[2] = regnames[1]; // 001
			if(bits[13] == 0 && bits[14] == 1 & bits[15] == 0) /* */ registers[2] = regnames[2]; // 010
			if(bits[13] == 0 && bits[14] == 1 & bits[15] == 1) /* */ registers[2] = regnames[3]; // 011
			if(bits[13] == 1 && bits[14] == 0 & bits[15] == 0) /* */ registers[2] = regnames[4]; // 100
			if(bits[13] == 1 && bits[14] == 0 & bits[15] == 1) /* */ registers[2] = regnames[5]; // 101
			if(bits[13] == 0 && bits[14] == 1 & bits[15] == 0) /* */ registers[2] = regnames[6]; // 110
			if(bits[13] == 1 && bits[14] == 1 & bits[15] == 1) /* */ registers[2] = regnames[7]; // 111

			// convert data processing registers to one string
			char * str3 = (char *) malloc(1 + strlen(opname)+ strlen(registers[1])+ strlen(registers[0]+ 4));
      		strcpy(str3, "   ");
      		strcat(str3, opname);
      		strcat(str3, " ");
      		strcat(str3, registers[2]);
      		strcat(str3, ",");
      		strcat(str3, registers[1]);
      		strcat(str3, ",");
      		strcat(str3, registers[0]);

			toPrint[counter] = str3; // place the new string into the array of things to be printed
			counter++; // increment counter to hold the next string to be printed
			addSubRegisters = 0; // finished so removing add/subtract tag
		}
	} // end of while for data processing 


	// print the strting thumb
	printf(".text\n.syntax unified\n.thumb\n");

	// loop through toPrint array and print collected strings
	for(i=0;i<counter;i++){
		printf("%s\n", toPrint[i]);
	}
}