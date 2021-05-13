#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 3000
#define MAXLEN 30

int cmp(const void *a, const void *b);

int main()
{
	char line[MAXLEN];
	int num[MAXNUM];
	int cnt=0;
	int i=0;
	while(fgets(line, MAXLEN, stdin)) 
	{
		if(*line == '\n') continue;
		num[i] = atoi(line);
		i++;
	}
	cnt = i;
	qsort(num, cnt, sizeof(int), cmp);
	for(i=0; i<cnt; i++)
		printf("%d\n", num[i]);
	
	return 0;
}

int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
