#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
void filecopy(int f1,int f2);
int main(int argc,char *argv[])
{
if(argc!=3)
{
printf("file not found ");
exit(1);
}
int fd1=open(argv[1], 0);
if(fd1==-1)
{
printf("\n Error in file opening.");
exit(1);
}
int fd2=creat(argv[2],0666);
if(fd2==-1)
{
printf("\n error while creating file ");
exit(1);
}
filecopy(fd1,fd2);
close(fd1);
close(fd2);
return 0;
}
void filecopy(int f1,int f2){
char buf[512];
int cnt;
while(cnt=read(f1, buf, sizeof(buf)))
{
write(f2,buf,cnt);
}
}

/*hosh@swapnil-ghosh-HP-Laptop-15s-eq2xxx:~/operatingsystem$ ./a.out sameprgmsamecode.c swapnil.c
swapnil-ghosh@swapnil-ghosh-HP-Laptop-15s-eq2xxx:~/operatingsystem$ ls
a.out           kernelcpuinfoo.c     sameprgmdiffcode.c  systemcall.c
fcfs.cpp        kernelmemoryinfoo.c  sameprgmsamecode.c  usingwaitt.c
fileargument.c  roundrobin.cpp       swapnil.c
swapnil-ghosh@swapnil-ghosh-HP-Laptop-15s-eq2xxx:~/operatingsystem$ cat sameprgmsamecode.c swapnil.c
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
*/
