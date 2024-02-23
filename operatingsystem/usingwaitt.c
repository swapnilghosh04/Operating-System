#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  pid_t p=fork();
  if(p<0)
  {
    printf("Unsuccessful Child Creation Case!");
    exit(1);
  }
  else if(p==0)
  {
    printf("\nHello, child process only.");
    printf("\nProcess ID: %d\n", getpid());
    exit(0);
  }
  else
  {
    printf("\nHello, parent process only.");
    printf("\nProcess ID: %d", getpid());
    wait(NULL);
    printf("\nChild Process exits...");
    exit(1);
  }
  return 0;
}

