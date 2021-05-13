#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1000

void getwd(char *l, char *w);

int main()
{
	int len;
	char line[MAXLEN];
	char word[MAXLEN];
	while(fgets(line, MAXLEN, stdin))
	{
		len = strlen(line);
		if(line[len-1] == '\n') line[len-1] = '\0';
		getwd(line, word);
		if(line[0]) printf("%s\n", word);
	}
}

void getwd(char *l, char *w)
{
	int len;
	int max = 0;
	char wd[MAXLEN];
	char *p = w;
	char d[4] = " ,.";
	p = strtok(l, d);
	while(p != NULL)
	{
		len = strlen(p);
		if(len > max)
		{
			max = len;
			strcpy(wd, p);
		}
		p = strtok(NULL, d);
	}
	strcpy(w, wd);
}
