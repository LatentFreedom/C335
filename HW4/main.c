/**********************************************************
 * main.c
 *
 * Author: Nick Palumbo
 *   Date Created: March 20, 2016
 *   Last Modified by: Nick Palumbo
 *   Date Last Modified: March 23, 2016
 *   Assignment: HW4
 *   Part of: Homework 4
 */

/* Copyright (c) 2015 The Trustees of Indiana University and
 * Indiana University Research and Technology Corporation.
 *
 * All rights reserved.
 *
 * Additional copyrights may follow
 */

/* Code: */
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "testvector.h"
#include "machine.h"
#include "flags.h"

uint32_t reg[16];
uint32_t psr;

int main(int argc, char *argv[]) {
    // Argument to test_instructions can be ALL to run all of tests or a specific
    // instruction can be tested by passing the name.
    // ADCS, ADDS, SUBS, ANDS, BICS, LSLS, ASRS
    // To run the instruction tests for all of the instructions, pass ALL
    
    // test_instructions(ANDS);
    // test_instructions(ADCS);
    // test_instructions(ADDS);
    // test_instructions(BICS);
    // test_instructions(LSLS);
    // test_instructions(ASRS);
    
  test_instructions(ALL);
  printf("%d command line arguments given.\n", argc);
  printf("string1 = %s\n",argv[1]);
  printf("string2 = %s\n",argv[2]);

  unsigned long arg1, arg2;

  arg1 = strtol(argv[1], NULL, 16);
  arg2 = strtol(argv[2], NULL, 16);

  printf("arg1 = %lu\n", arg1);
  printf("arg2 = %lu\n", arg2);
  
  unsigned long arg3 = arg1 + arg2 + 2;
  printf("sum = %lu\n", arg3);

  return (0);
}

void ands(int rn, int rm) {
    // Include your code to emulate the "and" instruction:
    // subs rn, rm
    // rn = index where operand1 is located in reg[], also destination for result
    // rm = index where operand2 is located in reg[]
    
    reg[rn] &= reg[rm];
    
    // Negative Flag
    if (reg[rn]&0x80000000) SET_N;
    else CLEAR_N;
    
    // Zero Flag
    if (!reg[rn]) SET_Z;
    else CLEAR_Z;
    
}

void adcs(int rn, int rm) {
    // Include your code to emulate the "adc" instruction:
    // adcs rn, rm
    // rn = index where operand1 is located in reg[], also destination for result
    // rm = index where operand2 is located in reg[]
    
    int originalRn = reg[rn];
    
    // 64 bit int for carry flag
    uint64_t Rn2 = (uint64_t) reg[rn];
    if (psr & 0x20000000)
        reg[rn] = reg[rn] + reg[rm] + 1;
    else
        reg[rn] += reg[rm];
    
    if (reg[rn]&0x80000000) SET_N;
    else CLEAR_N;
    
    // Zero Flag
    if (!reg[rn]) SET_Z;
    else CLEAR_Z;
    
    // Carry Flag
    if (reg[rn] < originalRn) SET_C;
    else CLEAR_C;
    
    // Overflow Flag
    // Most significant bit of inputs is 1 and of output is 0 OR
    // Most significant bit of input is 0 and of output is 1
    if (((originalRn & 0x80000000) && (reg[rm] & 0x80000000 && (!((uint32_t)reg[rn] & 0x80000000)))) ||
        (!(originalRn & 0x80000000) && !(reg[rm] & 0x80000000) && ((uint32_t) reg[rn] & 0x80000000))) SET_V;
    else CLEAR_V;
}

void adds(int rn, int rm) {
    // Include your code to emulate the "add" instruction:
    // adds rn, rm
    // rn = index where operand1 is located in reg[], also destination for result
    // rm = index where operand2 is located in reg[]
    
    int originalRn = reg[rn];
    
    // 64 bit int for carry flag
    uint64_t Rn2 = (uint64_t) reg[rn];
    if (psr & 0x20000000)
        reg[rn] = reg[rn] + reg[rm];
    else
        reg[rn] += reg[rm];
    
    if (reg[rn]&0x80000000) SET_N;
    else CLEAR_N;
    
    // Zero Flag
    if (!reg[rn]) SET_Z;
    else CLEAR_Z;
    
    // Carry Flag
    if (reg[rn] < originalRn) SET_C;
    else CLEAR_C;
    
    // Overflow Flag
    // Most significant bit of inputs is 1 and of output is 0 OR
    // Most significant bit of input is 0 and of output is 1
    if (((originalRn & 0x80000000) && (reg[rm] & 0x80000000 && (!((uint32_t)reg[rn] & 0x80000000)))) ||
        (!(originalRn & 0x80000000) && !(reg[rm] & 0x80000000) && ((uint32_t) reg[rn] & 0x80000000))) SET_V;
    else CLEAR_V;
}

void bics(int rn, int rm) {
    // Include your code to emulate the "bics" instruction:
    // bics rn, rm
    // rn = index where operand1 is located in reg[], also destination for result
    // rm = index where operand2 is located in reg[]
    
    reg[rn] &= ~reg[rm];
    
    //Negative Flag
    if (reg[rn]&0x80000000) SET_N;
    else CLEAR_N;
    
    // Zero Flag
    if (!reg[rn]) SET_Z;
    else CLEAR_Z;
}

void lsls(int rn, int rm) {
    // Include your code to emulate the "lsls" instruction:
    // lsls rn, rm
    // rn = index where operand1 is located in reg[], also destination for result
    // rm = index where operand2 is located in reg[]
    
    int originalRn = reg[rn];
    
    uint64_t Rn2 = (uint64_t) reg[rn];
    uint64_t Rm2 = (uint64_t) reg[rm];
    
    Rm2 = Rm2 & 0x000000ff; // Mask value for (0:7) bits
    
    if (Rm2 > 31) {Rm2 = 32;} // Clamp value for legal << input
    
    int c = (reg[rn] << (32 - reg[rm])) & 1;
    
    reg[rn] = (long) reg[rn] << (int) Rm2;
    
    Rn2 = (long) Rn2 << (int) Rm2; //Store same value in Rn2
    
    if (reg[rn]&0x80000000) SET_N;
    else CLEAR_N;
    
    // Zero Flag
    if (!reg[rn]) SET_Z;
    else CLEAR_Z;
    
    // Carry Flag
    // Rm2 was clamped, so we need to insure original reg[rm] is not greater than 32
    if ((Rn2 >> 32) && !(reg[rm] > 32)) SET_C;
    else CLEAR_C;
    
}

void asrs(int rn, int rm) {
    // Include your code to emulate the "asrs" instruction:
    // asrs rn, rm
    // rn = index where operand1 is located in reg[], also destination for result
    // rm = index where operand2 is located in reg[]
    
    int originalRn = reg[rn];
    int count = reg[rm];
    
    uint64_t Rm2 = (uint64_t) reg[rm];
    uint64_t Rn2 = (uint64_t) reg[rn];
    
    Rm2 = Rm2 & 0x000000ff;
    
    if (Rm2 >= 31) { Rm2 = 31;}
    
    reg[rn] = (int) reg[rn] >> (int) Rm2;
    
    //Shifting 1 less than Rm2 gives us the carry bit (last bit shifted out)
    Rn2 = (int) Rn2 >> ((int)Rm2 - 1);
    
    // Negative Flag
    if (reg[rn]&0x80000000) SET_N;
    else CLEAR_N;
    
    // Zero Flag
    if (!reg[rn]) SET_Z;
    else CLEAR_Z;
    
    //Carry Flag
    // Carry bit is least significant bitA
    if (Rn2 & 0x00000001) SET_C;
    else CLEAR_C;
}


void longLongAddition(int rn, int rm){
  
}
/* main.c ends here */
