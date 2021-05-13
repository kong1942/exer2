#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 1024

int main()
{
    char line[MAXLEN];
    char line2[MAXLEN];
    char *ptr;
    char *qtr;

    while(fgets(line, MAXLEN, stdin))
    {
        ptr = line;
        qtr = line2;
        while(*ptr)
        {
            while(*ptr == ' ') ptr++;
            while(*ptr && *ptr != ' ')
            {
                *qtr++ = *ptr++;
            }
            if(*ptr) *qtr++ = *ptr++;
        }
        if(*(qtr-2) == ' ') {*(qtr-2) = '\n'; *(qtr-1) = '\0';}
        else *qtr = '\0';
        printf("%s", line2);
    }

    return 0;
}