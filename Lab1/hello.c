#include <stdio.h>
#include <unistd.h> // needed for sleep()
#include <stdlib.h>
#include <sys/stat.h> // needed for mkdir()

void make_dir(int i);

int main() 
{ 
	int i = 1;
  	while(i > 0) 
	{
	  while(i % 5 != 0) 
	  {
	  	make_dir(i);
	  	i++;
	  }
	  printf("Hello, world.\n");
	  sleep(3);
	  i++;
	}
	return 0;
}

void make_dir(i)
{
  char str[20];
  sprintf(str, "%d", i); //convert int i into string str
  char directoryName[20];
  sprintf(directoryName, "%s%s", "HelloWorld", str); // append both strings
  mkdir(directoryName,0777);
}
