#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1024

struct Lnode *find(struct Lnode *L, char *key);
struct Lnode *insert(struct Lnode *L, char *key);
void trave(struct Lnode *h);

struct Lnode
{
    char *key;
    struct Lnode *next;
};

int main()
{
    int len;
    char line[MAXLEN];
    struct Lnode *head = NULL;
    while(fgets(line, MAXLEN, stdin))
    {
        len = strlen(line);
        if(line[len-1] == '\n') line[len-1] = '\0';
        head = insert(head, line);
    }
    trave(head);

    struct Lnode *p = head;
    struct Lnode *q;
    while(p)
    {
        q = p->next;
        free(p->key);
        free(p);
        p = q;
    }
    return 0;
}

struct Lnode *insert(struct Lnode *L, char *key)
{
    struct Lnode *f;
    if((f = find(L, key)) || key[0] == '\0') return L;
    struct Lnode *head;
    head = (struct Lnode *)malloc(sizeof(struct Lnode));
    head->next = L;
    head->key = strdup(key);
    return head;
}

struct Lnode *find(struct Lnode *L, char *key)
{
    if(L == NULL) return NULL;
    struct Lnode *ptr = L;
    while(ptr)
    {
        if(!strcmp(ptr->key, key)) return ptr;
        else ptr = ptr->next;
    }
    return NULL;
}

void trave(struct Lnode *h)
{
    if(h == NULL) return;
    struct Lnode *p = h;
    while(p)
    {
        printf("%s", p->key);
	if(p->next) printf("\n");
        p = p->next;
    }
}
