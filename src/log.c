#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


// Function to print welcome logo to the temrinal at startup.
void welcome() 
{
        int fd = open("/home/mossberg/repos/httpserver/static/logo", O_RDONLY);
        if (fd < 0) {
                printf("log:welcome:open : %s\n", strerror(errno));
                return;
        }

        char ch;
        while (read(fd, &ch, sizeof(char)) > 0) {
               putchar(ch); 
        }

        return;
}
