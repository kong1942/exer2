#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1024
#define TRUE 1
#define FALSE 0

int main()
{
    int len;
    int flag;
    char line[MAXLEN];
    while(fgets(line, MAXLEN, stdin))
    {
        flag = TRUE;
        len = strlen(line);
        if(line[len-1] == '\n') line[len-1] = '\0';
        len--;
        for(int i=0; i<len/2; i++)
        {
            if(line[i] != line[len-i-1]) flag = FALSE;
        }
        if(flag) printf("%s\n", line);
    }
    return 0;
}