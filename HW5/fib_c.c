/********************************************************** 
* fibs_c.c
* 
* Author: Nick Palumbo
*   Date Created: March 29, 2016
*   Last Modified by: Nick Palumbo
*   Date Last Modified: March 29, 2016
*   Assignment: HW5
*   Part of: HW5
*/

/* Copyright (c) 2004-2007 The Trustees of Indiana University and 
 * Indiana University Research and Technology Corporation.  
 * 
 * All rights reserved. 
 * 
 * Additional copyrights may follow 
 */

/* Code: */

int fib_c(int num) {
  int prev2=1;
  int prev1=1; 
  int val=1;
  int i; 
  if (num==0) return 0;
  else if (num==1) return 1;
  else {
    for (i=0;i<(num-2);i++) {
      val = prev1 + prev2;
      prev2 = prev1;
      prev1 = val;
    }
    return (val);
  }
}

/* fib_c.c ends here */
