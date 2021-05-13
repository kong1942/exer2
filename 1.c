#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1100

struct BST
{
	char *key;
	struct BST *L;
	struct BST *R;
};

void insert(struct BST *r, char *line)
{
	if(line[0] == '\0') return;
	struct BST *p = r;
	struct BST *q = r;
	char rl = '\0';
	while(q)
	{
		if(strcmp(q->key, line) < 0)
		{
			p = q;
			q = q->R;
			rl = 'R';
		}
		else if(strcmp(q->key, line) >= 0)
		{
			p = q;
			q = q->L;
			rl = 'L';
		}
	}
	if(q == NULL)
	{
		q = (struct BST *)malloc(sizeof(struct BST));
		q->key = strdup(line);
		q->L = NULL;
		q->R = NULL;
		if(rl == 'R') p->R = q;
		else if(rl == 'L') p->L = q;
	}
}

void trave(struct BST *r)
{
	if(r == NULL) return;
       	trave(r->L);
	printf("%s\n", r->key);
       	trave(r->R);
}

void travefree(struct BST *r)
{
	if(r == NULL) return;
	travefree(r->L);
	travefree(r->R);
	free(r->key);
	free(r);
}

int main()
{
	int len;
	char line[MAXLEN];
	struct BST r;
	while(fgets(line, MAXLEN, stdin))
	{
		len = strlen(line);
		if(line[len-1] == '\n') line[len-1] = '\0';
		if(line[0] != '\0')
		{
			r.key = strdup(line);
			r.L = NULL;
			r.R = NULL;
		}
		else continue;
		while(fgets(line, MAXLEN, stdin))
		{
			len = strlen(line);
			if(line[len-1] == '\n') line[len-1] = '\0';
			insert(&r, line);
		}
		trave(&r);
		free(r.key);
		travefree(r.L);
		travefree(r.R);
	}
}
