#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 300

struct Lnode *insert(struct Lnode *L, char *key);
struct Lnode *find(struct Lnode *L, char *key);
void traveMax(struct Lnode *L);

struct Lnode
{
    char *key;
    int cnt;
    struct Lnode *next;
};

int main()
{
    char line[MAXLEN];
    char *word;
    char d[3] = " \n";
    struct Lnode *head;
    head = NULL;
    while(fgets(line, MAXLEN, stdin))
    {
        word = strtok(line, d);
        while(word != NULL)
        {
            if(*word == 'a' || *word == 'A') head = insert(head, word);
            word = strtok(NULL, d);
        }
    }
    traveMax(head);
    
    return 0;
}

struct Lnode *insert(struct Lnode *L, char *key)
{
    struct Lnode *f;
    if((f = find(L, key)) || key[0] == '\0') return L;
    struct Lnode *head;
    head = (struct Lnode *)malloc(sizeof(struct Lnode));
    head->key = strdup(key);
    head->cnt = 1;
    if(L != NULL)
    {
        struct Lnode *p = L;
        struct Lnode *q;
        if(strcmp(key, p->key) < 0)
        {
            head->next = L;
            return head;
        }
        else
        {
            while(p && strcmp(key, p->key) > 0)
	    {
		    q = p;
		    p = p->next;
	    }
	    head->next = q->next;
            q->next = head;
            return L;
        }
    }
    else 
    {
	    head->next = L;
	    return head;
    }
}

struct Lnode *find(struct Lnode *L, char *key)
{
    if(L == NULL) return NULL;
    struct Lnode *p = L;
    while(p)
    {
        if(!strcmp(p->key, key)) {p->cnt++; return p;}
        else p = p->next;
    }
    return NULL;
}

void traveMax(struct Lnode *L)
{
    if(L == NULL) return;
    struct Lnode *p = L;
    struct Lnode *h = L;
    struct Lnode *last;
    int max=0;

    while(p)
    {
        while(p)
        {
            if(p->cnt > max) max = p->cnt;
            p = p->next;
        }
        p = h;
        while(p)
        {
            if(p->cnt == max) 
            {
                printf("%s %d\n", p->key, p->cnt);
                if(p != h)
                {
                    last->next = p->next;
                    free(p->key);
                    free(p);
                    p = last->next;
                }
                else
                {
                    h = h->next;
                    free(p->key);
                    free(p);
                    p = h;
                }
            }
            else
            {
                last = p;
                p = p->next;
            }
        }
        p = h;
        max = 0;
    }
}
