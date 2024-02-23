#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  printf("\nThe kernel version is: \n");
  system("cat /proc/sys/kernel/osrelease");
  printf("\nThe CPU space is: \n");
  system("cat /proc/cpuinfo | head -n9 | tail -n8");
  printf("\nThe amount of CPU time is: \n");
  system("cat /proc/uptime \n");
  system("cat /proc/uptime | cut -f1 -d" "\n");
  return 0;
}
