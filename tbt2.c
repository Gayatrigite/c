#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    int lbit;
    int rbit;
};

struct node * createNode(int data) {
    struct node * newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->lbit = 0;
    newNode->rbit = 0;
    return newNode;
}

struct node *insert(struct node *root, int data) {
    struct node *newNode = createNode(data);
    if (root == NULL) {
        root = newNode;
    } else {
        struct node *current = root;
        while (1) {
            if (data < current->data){
                if (current->lbit == 0) { 
                    newNode->left = current->left; 
                    newNode->right = current;  
                    current->left = newNode;
                    current->lbit = 1;
                    break;
                } 
                else {
                    current = current->left;  
                }
            } 
            else {
                if (current->rbit == 0) {
                    newNode->right = current->right;
                    newNode->left = current;
                    current->right = newNode;
                    current->rbit = 1;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
    return root;
}

struct node *inorderSuccessor(struct node *current) {
    if (current->rbit == 0) {
        return current->right;
    } else {
        current = current->right;
        while (current->lbit == 1) {
            current = current->left;
        }
        return current;
    }
}

void inorderTraversal(struct node *root) {
    struct node *current = root;
    while (current->lbit == 1) {
        current = current->left;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = inorderSuccessor(current);
    }
    printf("\n");
}
void preorder(struct node * root){
    struct node * temp = root;
    while(temp != NULL){
        printf("%d ", temp->data);
        if(temp->lbit == 1){
            temp = temp->left;
        }
        else if(temp->rbit == 1){
            temp = temp->right;
        }
        else{
            while(temp != NULL && temp->rbit == 0){
                temp = temp->right;
            }
            if(temp != NULL){
                temp = temp->right;
            }
        }
    }
    printf("\n");
}

int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf ("Inorder traversal ");
    inorderTraversal(root);
    printf("\nPreorder traversal ");
    preorder(root);
    return 0;
}