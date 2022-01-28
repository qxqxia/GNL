#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    char    *str;
    int fd;

    fd = open ("text.txt", O_RDONLY);
    while (1)
    {
        str = get_next_line(fd);
        if (!str)
            break;
        printf("%s", str);
        free(str);
    }
    return (0);
}
