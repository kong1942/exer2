#include <stdio.h>
#include <string.h>
#include <ctype.h>
char *getword(char *text,char *word){
	char *ptr = text;
	char *qtr = word;
	while((isspace(*ptr)||*ptr==','||*ptr=='.') && *ptr){
		ptr++;
	}
	while(!(isspace(*ptr)||*ptr==','||*ptr=='.') && *ptr){
		*qtr++ = *ptr++;
	}
	*qtr = '\0';
	if(qtr - word==0){
		return NULL;
	}
	return ptr;
}


int main(){
	char line[2000];
	char word[200];
	char *ptr;
	char *qtr;
	int max=0;
	while(fgets(line,2000,stdin)){
		ptr = line;
		while(ptr = getword(ptr,word)){
			if(strlen(word)>max){
				max = strlen(word);
				qtr=strdup(word);
			}	
		}
		printf("%s\n",qtr);
		max=0;
	}
}
