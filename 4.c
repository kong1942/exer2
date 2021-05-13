#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXNUM 1500
#define MAXLEN 4096

struct stack
{
	double num[MAXNUM];
	double *top;
	double *bottom;
};

void getterm(char *line);

int main()
{
	int len;
	char line[MAXLEN];
	struct stack s;
	s.top = s.num;
	s.bottom = s.num;
	while(fgets(line, MAXLEN, stdin))
	{
		len = strlen(line);
		if(line[len-1] == '\n') line[len-1] = '\0';
		getterm(line);
	}
	return 0;
}

void getterm(char *line)
{
	int f = 0;
	double a, b;
	struct stack s;
	s.top = s.num;
	s.bottom = s.num;
	char word[MAXLEN];
	char *p = line;
	char *q = word;
	if(line[0] == '\0') return;
	while(*p)
	{
		q = word;
		while(*p && isspace(*p)) p++;
		while(*p && !isspace(*p)) *q++ = *p++;
		*q = '\0';
		if(!strcmp(word, "+"))
		{
			*s.top--;
			b = *s.top;
			*s.top--;
			a = *s.top;
			*s.top = a + b;
			s.top++;
		}
		else if(!strcmp(word, "-"))
		{
			*s.top--;
			b = *s.top;
			*s.top--;
			a = *s.top;
			*s.top = a - b;
			s.top++;
		}
		else if(!strcmp(word, "*"))
		{
			*s.top--;
			b = *s.top;
			*s.top--;
			a = *s.top;
			*s.top = a * b;
			s.top++;
		}
		else if(!strcmp(word, "/"))
		{
			*s.top--;
			b = *s.top;
			*s.top--;
			a = *s.top;
			*s.top = a / b;
			s.top++;
		}
		else if(word[0] != '\0')
		{
			f = 1;
			*s.top = atof(word);
			s.top++;
		}
	}
	if(f)
	{
		s.top--;
		printf("%.2f\n", *s.bottom);
	}
}
