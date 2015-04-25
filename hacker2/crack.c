#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#define _XOPEN_SOURCE
#include <unistd.h>

int main(int argc, string argv[])
{
    if ( argc != 2 ) {
        printf("Usage: crack cypher\n");
        return -1;
    }

    //char* cypher = GetString();
    FILE* fp;
    char line[128];

    fp = fopen("/usr/share/dict/words", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while (fgets (line, sizeof line, fp) != NULL)
    {
        char *p = line;
        p[strlen(p)-1] = "t";
        printf("**%s**\n", line);
    }
    
    fclose(fp);

    if (line)
        free(line);

    return 0;
}
