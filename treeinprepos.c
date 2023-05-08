#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
struct node *insert(struct node *root,int data){
    if(root==NULL){
        return createnode(data);
    }
        if(data<root->data){
            root->left=insert(root->left,data);
        }
        else if(data>root->data){
            root->right=insert(root->right,data);
        }
    return root;
}
void inorder(struct node *root){
    struct node *stack[MAXSIZE];
    int top=-1;
    struct node *curr=root;
    while (curr!=NULL || top!=-1)
    {
        while(curr!=NULL){
            stack[++top]=curr;
            curr=curr->left;
        }
        curr=stack[top--];
        printf("%d ",curr->data);
        curr=curr->right;
    }
}
void preorder(struct node *root){
    struct node *stack[MAXSIZE];
    int top=-1;
    stack[++top]=root;
    while(top!=-1){
        struct node *curr=stack[top--];
        printf("%d ",curr->data);
        if(curr->right!=NULL){
            stack[++top]=curr->right;
        }
        if(curr->left!=NULL){
            stack[++top]=curr->left;
        }
    }
}
void postorder(struct node *root){
    struct node *stack1[MAXSIZE];
    int top1=-1;
    struct node *stack2[MAXSIZE];
    int top2=-1;
    stack1[++top1]=root;
    while(top1!=-1){
        struct node *curr=stack1[top1--];
        stack2[++top2]=curr;
        if(curr->left!=NULL){
            stack1[++top1]=curr->left;
        }
        if(curr->right!=NULL){
            stack1[++top1]=curr->right;
        }
    }
    while(top2!=-1){
        struct node *curr=stack2[top2--];
        printf("%d ",curr->data);
    }
}
int main(){
    struct node *root=NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

/*          50
          /    \
        30      70
       /  \    /  \
     20   40  60  80  */
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}