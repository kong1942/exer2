#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode{
    char key[70];
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
    if(strcmp(T->key,key)>=0){
        T->Lchild = insert(T->Lchild, key);
    }
    else if(strcmp(T->key,key)<0){
        T->Rchild = insert(T->Rchild, key);
    }
    return T;
}

void inorder(struct tnode *T){
    if(T==NULL) return;
    inorder(T->Lchild);
    printf("%s\n",T->key);
    inorder(T->Rchild);
}



int main(){

    char line[1100];
    struct tnode *root = NULL;

    while(scanf("%s",line)!=EOF){
        root = insert(root, line);
    }
    inorder(root);
    free(root);
    return 0;
}
