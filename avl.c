#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
 
int getHeight(struct Node *n){
    if(n==NULL)
        return 0;
    return n->height;
}
 
struct Node *createNode(int key){
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
 
int max (int a, int b){
    return (a>b)?a:b;
}
 
int getBalanceFactor(struct Node * n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}
 
struct Node* rightRotate(struct Node* y){
    struct Node* x = y->left;
    struct Node* T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
 
    return x;
}
 
struct Node* leftRotate(struct Node* x){
    struct Node* y = x->right;
    struct Node* T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
 
    return y;
}
 
struct Node *insert(struct Node* node, int key){
    if (node == NULL)
        return  createNode(key);
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);
 
    //LL
        if(bf>1 && key < node->left->key){
            return rightRotate(node);
        }
    //RR
        if(bf<-1 && key > node->right->key){
            return leftRotate(node);
        }
    //LR
    if(bf>1 && key > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    //RL
    if(bf<-1 && key < node->right->key){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    return node;
}
 
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node *root)
{
    if(root != NULL)
    {
        preOrder(root->left);
        preOrder(root->right);
        printf("%d ", root->key);
    }
}

void inOrder(struct Node *root)
{
    if(root != NULL)
    {
        preOrder(root->left);
        printf("%d ", root->key);
        preOrder(root->right);
    }
}
void DisplayLevel(struct Node *root){
    if(root==NULL){
        return;
    }
    //create a queue for level-order traversal
    struct Node *queue[100];
    int front=0, rear=0;
    queue[rear++]=root;
    //loop until the queue is empty
    while(front<rear){
        //get the node at the front of the queue
        struct Node *node=queue[front++];
        //print the node's data
        printf("%d ",node->key);
        //enqueue its left and right children if they exist
        if(node->left!=NULL){
            queue[rear++]=node->left;
        }
        if(node->right!=NULL){
            queue[rear++]=node->right;
        }
    }
}

int main(){
    struct Node * root = NULL;
 
 
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    printf("Preorder :");
    preOrder(root);
    printf("\n");
    printf("Postorder :");
    postOrder(root);
    printf("\n");
    printf("Inorder :");
    inOrder(root);
    printf("\nDisplay level wise ");
    DisplayLevel(root);
    return 0;
}
