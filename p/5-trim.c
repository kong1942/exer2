#include <stdio.h>
#include <ctype.h>
char *getword(char *text, char *word){
    char *ptr = text;
    char *qtr = word;
    while(isspace(*ptr) && *ptr){
        ptr++;
    }
    while(!isspace(*ptr) && *ptr){
        *qtr++ = *ptr++;
    }
    *qtr = '\0';
    if(qtr - word == 0){
        return NULL;
    }
    return ptr;
 
}
int main(int argc , char **argv){
    char line[1024];
    char word[1024];
    char *ptr;
    int flag= 0 ;
    while(fgets(line,1024,stdin)){
        ptr = line;
        while(ptr = getword(ptr , word)){
            if(flag==0){
                printf("%s",word);
                flag = 1;
            }
            else {
                printf(" %s",word);
            }
        }
        printf("\n");
        flag = 0;
    }
}
