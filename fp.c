#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define		UP	0
#define		LEFT	1
#define		MIDDLE	2
#define		RIGHT	4

#define		F4	KEY_F4
#define		F5	KEY_F5
#define		F6	KEY_F6

int main(int argc, char** argv)
{
    if (argc < 2)
        exit(1);

    char *buff;
    buff = calloc(2, sizeof(char));

    // open file readonly
    int handle = open(argv[1], O_RDONLY);
    if (handle < 0)
        perror("OPEN");

    while (read(handle, buff, 2))
    {
        // read 2 bytes into buff, but we only
        // care about the first.
        if (buff[0] & LEFT)
            printf("LEFT\n");
        else if (buff[0] & MIDDLE)
            printf("MIDDLE\n");
        else if (buff[0] & RIGHT)
            printf("RIGHT\n");
        else if (buff[0] & UP)
            printf("UP\n");
    }
}
