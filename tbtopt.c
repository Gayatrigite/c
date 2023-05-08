#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
    int lbit;
    int rbit;
};
struct node *createnode(int data){
    struct node *newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->lbit=0;
    newnode->rbit=0;
    return newnode;
}
struct node *insert(struct node *root,int data){
    struct node *newnode=createnode(data);
    if(root==NULL){
        return root=newnode;
    }
    else{
        struct node *curr=root;
        while(1){      
            if(data<curr->data){
                if(curr->lbit==0){
                    newnode->left=curr->left;
                    newnode->right=curr;
                    curr->left=newnode;
                    curr->lbit=1;
                    break;
                }
                else{
                curr=curr->left;
                }
            }
            if(curr->rbit==0){
                newnode->right=curr->right;
                newnode->left=curr;
                curr->right=newnode;
                curr->rbit=1;
                break;
            }
            else{
                curr=curr->right;
            }
        }
    }
    return root;
}
struct node *inordersuccessor(struct node *curr){
    if(curr->rbit==0){
        return curr->right;
    }
    else{
        curr=curr->right;
        while(curr->lbit==1){
            curr=curr->left;
        }
    }
    return curr;
}
void inorder(struct node *root){
    struct node *curr=root;
    while(curr->lbit==1){
        curr=curr->left;
    }
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=inordersuccessor(curr);
    }
    printf("\n");
}
void preorder(struct node *root){
    struct node *temp=root;
    while(temp!=NULL){
        printf("%d ",temp->data);
    if(temp->lbit==1){
        temp=temp->left;
    }
    else if(temp->rbit==1){
        temp=temp->right;
    }
    else{
        while(temp!=NULL && temp->rbit==0){
            temp=temp->right;
        }
        if(temp!=NULL){
            temp=temp->right;
        }
    }
    }
    printf("\n");
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
    inorder(root);
    preorder(root);
    return 0;
}