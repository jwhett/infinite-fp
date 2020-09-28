#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    // declare a buff
    // open raw device file for reading
    // read bytes into buff
    // communicate state
    // 
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
        int numBytes = read(handle, buff, 2); // read 2 bytes into buff
        printf("NUMBYTES: %d\n", numBytes);
        printf("Buff: %x%x\n", buff[0], buff[1]);
    }
}
