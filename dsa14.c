
#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node * createnode(int data){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int isBST(struct node * root){
    static struct node * prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
void insert(struct node * root,int key){
    struct node *prev = NULL;
    while(root!=NULL){
        prev=root;
        if(key==root->data){
            printf("cannot insert");
            return;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node * new = createnode(key);
    if(key<prev->data){
       prev->left = new;
    }
    else{
       prev->right = new;
    }
}
int main(){
    // for a tree to be BST its inorder must be in ascending
    // no duplicates allowed in bst
    struct node *p = createnode(4);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);
     p->left = p1;
     p->right = p2;
     p1->left = p3;
     p1->right = p4;

     insert(p,7);
     printf("%d",p->right->right->data);
}