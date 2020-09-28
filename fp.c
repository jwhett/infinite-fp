#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define		LEFT	1
#define		MIDDLE	2
#define		RIGHT	4


int main(int argc, char** argv)
{
    // TODO: compare bytes in buff to ID state

    if (argc < 2)
        exit(1);

    char *buff;
    buff = calloc(2, sizeof(char));

    int handle = open(argv[1], O_RDONLY); // open file readonly
    if (handle < 0)
        perror("OPEN");

    while (1)
    {
        read(handle, buff, 2); // read 2 bytes into buff
        if (buff[0] & LEFT)
            printf("LEFT\n");
        if (buff[0] & MIDDLE)
            printf("MIDDLE\n");
        if (buff[0] & RIGHT)
            printf("RIGHT\n");
       // printf("Buff: %x\n", buff[0]);
    }
}
