#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 2048
#define MAXNUM 1000

struct BST
{
	char *key;
	struct BST *L;
	struct BST *R;
};

struct Lnode
{
	struct BST *key;
	struct Lnode *next;
};

struct BST *insert(struct BST *r, char *key);
void levelOrderTraversal(struct BST *r);
struct Lnode *push(struct Lnode *q, struct BST *r);
void t(struct BST *r);

int main()
{
	int len;
	char line[MAXLEN];
	struct BST *r = NULL;
	while(fgets(line, MAXLEN, stdin))
	{
		len = strlen(line);
		if(line[len-1] == '\n') line[len-1] = '\0';
		r = insert(r, line);
	}
	levelOrderTraversal(r);
	//t(r);
	return 0;
}

struct BST *insert(struct BST *r, char *key)
{
	if(key[0] == '\0') return r;
	struct BST *p;
	if(r == NULL)
	{
		p = (struct BST *)malloc(sizeof(struct BST));
		p->key = strdup(key);
		p->L = NULL;
		p->R = NULL;
		return p;
	}
	else
	{
		char rl = '\0';
		struct BST *q;
		p = r;
		while(p)
		{
			if(strcmp(p->key, key) > 0)
			{
				q = p;
				p = p->L;
				rl = 'l';
			}
			else if(strcmp(p->key, key) < 0)
			{
				q = p;
				p = p->R;
				rl = 'r';
			}
			else return r;
		}
		if(rl == 'l')
		{
			q->L = insert(p, key);
		}
		else if(rl == 'r')
		{
			q->R = insert(p, key);
		}
		return r;
	}
}

void levelOrderTraversal(struct BST *r)
{
	if(r == NULL) return;
	struct BST *x;
	struct BST *p = r;
	struct Lnode *l = NULL;
	struct Lnode *h;
	l = push(l, p);
	while(l)
	{
		x = l->key;
		printf("%s\n", x->key);
		if(x->L) l = push(l, x->L);
		if(x->R) l = push(l, x->R);
		h = l;
		l = l->next;
		free(x->key);
		free(x);
		free(h);
	}
}

struct Lnode *push(struct Lnode *l, struct BST *r)
{
	struct Lnode *p = (struct Lnode *)malloc(sizeof(struct Lnode));
	p->key = r;
	p->next = NULL;
	if(l == NULL)	return p;
	struct Lnode *q = l;
	while(q->next) q = q->next;
	q->next = p;
	return l;
}

void t(struct BST *r)
{
	if(r == NULL) return;
	t(r->L);
	printf("%s\n", r->key);
	t(r->R);
}
