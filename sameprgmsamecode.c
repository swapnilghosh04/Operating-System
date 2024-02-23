#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  pid_t p=fork();
  if(p<0)
    printf("Unsuccesful Child Creation Case!");
  else
  {
    printf("\nOutput of the fork ID: %d", p);
    printf("\nProcess ID: %d", getpid());
  }
  return 0;
}
