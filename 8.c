#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 7

long long int pow65(int a, int b);

int main()
{
	int len;
	char line[MAXLEN];
	long long int hash65 = 0;
	while(fgets(line, MAXLEN, stdin))
	{
		hash65 = 0;
		len = strlen(line);
		if(line[len-1] == '\n') {line[len-1] = '\0'; len--;}
		for(int i=0; i<len; i++)
		{
			if(isalpha(line[len-i-1])) hash65 += (pow65(65, i) * line[len-i-1]);
		}
		if(hash65 != 0) printf("%lld\n", hash65);
	}
}

long long int pow65(int a, int b)
{
	long long int x = 1;
	for(int i=0; i<b; i++)
		x *= a;
	return x;
}
