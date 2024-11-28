#include <stdio.h>

#include "log.h"


/*
* Function to log the server name with ascii art.
* Takes the path to the ascii art as argument. */
void ascii_art(char *path) 
{
    FILE *fp = fopen(path, "r");
    if (fp == NULL) 
    {
        return;
    }   

    printf(CYAN);
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp)) 
    {
        printf("%s", buffer);
    }
    
    printf("%s\n\n", RESET);
    fclose(fp);
}