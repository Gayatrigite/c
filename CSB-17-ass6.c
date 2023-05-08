// WAP to create a binary tree and perform non-recursive preorder, inorder and postorder traversal on it 

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void inorder(struct Node* root) {
    struct Node* stack[MAX_SIZE];
    int top = -1;
    struct Node* curr = root;
    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

void preorder(struct Node* root) {
    struct Node* stack[MAX_SIZE];
    int top = -1;
    stack[++top] = root; //The root node of the binary tree is pushed onto the stack.
    while (top != -1) {
        struct Node* curr = stack[top--]; //Inside the while loop, the top node of the stack is popped.
        printf("%d ", curr->data);
        if (curr->right != NULL)  //If the popped node has a right child, it is pushed onto the stack
            stack[++top] = curr->right;
        if (curr->left != NULL) //If the popped node has a left child, it is pushed onto the stack. Note that the left child is pushed onto the stack after the right child, so that it will be popped off the stack first and visited before the right child.
            stack[++top] = curr->left;
    }
}

void postorder(struct Node* root) {
    struct Node* stack1[MAX_SIZE];
    int top1 = -1;
    struct Node* stack2[MAX_SIZE];
    int top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1) {
        struct Node* curr = stack1[top1--];
        stack2[++top2] = curr;
        if (curr->left != NULL)
            stack1[++top1] = curr->left;
        if (curr->right != NULL)
            stack1[++top1] = curr->right;
    }
    while (top2 != -1) {
        struct Node* curr = stack2[top2--];
        printf("%d ", curr->data);
    }
}

int main() {
    struct Node* root = NULL;
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
