#include <stdio.h>

int main(void)
{
// Example 1
int j;
j += 6; // error

// Example 2
int s = 3;
if (s == 66) { // error
  printf("Hello there, General Kenobi!");
}

// Example 3
int i = 0;
while (i++ < 1) { // error
  printf("I'm still working on fixing Valgrind errors!\n");
}

return (0);
}
