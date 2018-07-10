#include <stdio.h>
#include <stdlib.h>

typedef struct CELL *LIST;

struct CELL 
{
  int val;
  LIST next;
};

int is_operator(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        default:
            return 0;
    }
}

int main(int argc, char** argv)
{
	struct LIST *root;
  	struct LIST *a = root;
    int choice;

    LIST c = (LIST) malloc(sizeof(struct CELL));

    char quit[3] = "EOF";

  	while(1)
    {
    	printf("RPN calculator\n\n");
   		printf("p: prints the top element and leaves the stack unchanged.\n");
    	printf("f: prints the entire contents of the stack, top to bottom,\n   with each entry on a separate line, and leaves the stack unchanged.\n");
    	printf("c: clears the stack completely.\n");
    	printf("q: quits the program.\n");
    	printf("EOF: quits the program.\n\n");

        printf("Enter an equation in postfix form: ");
    
        scanf(" %d", &choice);



        if(choice == 'q' || choice == 'Q' || choice == quit)
        {
        	return 0;
        }
    }
}