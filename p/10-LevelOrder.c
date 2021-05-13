#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode{
    char key[2500];
    struct tnode *Lchild, *Rchild;
};

struct tnode *insert(struct tnode *T, char *key){
    if(T==NULL){
        struct tnode *p = (struct tnode *) malloc(sizeof(struct tnode));
        strcpy(p->key, key);
        p->Lchild = NULL;
        p->Rchild = NULL;
        return p;
    }
    if(strcmp(T->key,key)>0){
        T->Lchild = insert(T->Lchild, key);
    }
    else if(strcmp(T->key,key)<0){
        T->Rchild = insert(T->Rchild, key);
    }
    return T;
}

int height(struct tnode* node)
{
    if (node==NULL)
        return 0;
    else
    {
        int lheight = height(node->Lchild);
        int rheight = height(node->Rchild);

        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

void printGivenLevel(struct tnode* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%s\n", root->key);
    else if (level > 1)
    {
        printGivenLevel(root->Lchild, level-1);
        printGivenLevel(root->Rchild, level-1);
    }
}

void printLevelOrder(struct tnode* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}

int main(){

    char line[2500];
    struct tnode *root = NULL;

    while(scanf("%s",line)!=EOF){
        root = insert(root, line);
    }
    printLevelOrder(root);
    free(root);
    return 0;
}
