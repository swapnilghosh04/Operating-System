#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char command[1024];
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(0);
    }
    sprintf(command,"stat %s",argv[1]);
    system(command);
    return 0;
}

/*./a.out sameprgmsamecode.c
  File: sameprgmsamecode.c
  Size: 266       	Blocks: 8          IO Block: 4096   regular file
Device: 259,7	Inode: 11280149    Links: 1
Access: (0664/-rw-rw-r--)  Uid: ( 1000/swapnil-ghosh)   Gid: ( 1000/swapnil-ghosh)
Access: 2024-02-23 19:18:56.271266925 +0530
Modify: 2024-02-23 19:17:36.387959077 +0530
Change: 2024-02-23 19:18:26.530808072 +0530
 Birth: 2024-02-23 19:17:36.387959077 +0530*/

