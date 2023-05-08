// WAP to perform operations on BST create insert delete mirrorimage levelwisedisplay heightoftree displayleafnodes 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
int data;
struct node* left;
struct node* right;
};
struct node *create(int data){
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
temp->left=temp->right=NULL;
return temp;
}

struct node *insert(struct node* root,int data){
if(root==NULL){
root=create(data);
}
else if(data<root->data){
root->left=insert(root->left,data);
}
else{
root->right=insert(root->right,data);
}
return root;
}

struct node* find_min(struct node*root){
if(root==NULL){
return NULL;
}
else if(root->left!=NULL)//nodewithminimumvaluewillhavenoleftchild
{
return find_min(root->left);
}
return root;
}

struct node* delete(struct node* root , int data){
    //search the item that is to be deleted
    if(root==NULL){
        return NULL;
    }
    if(data>root->data){
        root->right=delete(root->right,data);
    }
    else if(data<root->data){
        root->left=delete(root->left,data);
    }
    else{
        //CASE:1 NO child
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        //CASE 2: ONE child
        else if(root->left==NULL || root->right==NULL){
            struct node *temp;
            if(root->left==NULL){
                temp=root->right;
            }
            else{
                temp=root->left;

            }
            free(root);
            return temp;
        }
        else{
            //CASE 3: TWO children
            struct node *temp=find_min(root->right); //find minimum node in right subtree
            //replace min value in root->temp
            root->data=temp->data; 
            //delete the duplicate value from right subtree
            root->right=delete(root->right,temp->data);
        }
}
return root;
}

struct node*mirror_image(struct node* root){
if(root==NULL){
return NULL;
}
struct node* temp =root->left;
root->left=mirror_image(root->right);
root->right =mirror_image(temp);
return root;
}

// void CurrentLevel(struct node*root,int level){
// if(root==NULL){
// return;
// }
// if(level==1){//BASECASE
// printf("%d"
// ,root->data);
// }
// else if(level>1){
// CurrentLevel(root->left,level-1);//decrementtomovedownthe levelsoftheBST
// CurrentLevel(root->right,level-1);
// }
// }
// void DisplayLevel(struct node *root){
// int h=Height(root);
// int i;
// for(int i=1;i<=h;i++){
// printf("\nLevel:%d \n"
// ,i);
// CurrentLevel(root , i ); //printeachlevel
// }
// printf("\n");
// }

void DisplayLevel(struct node *root){
    if(root==NULL){
        return;
    }
    //create a queue for level-order traversal
    struct node *queue[100];
    int front=0, rear=0;
    queue[rear++]=root;
    //loop until the queue is empty
    while(front<rear){
        //get the node at the front of the queue
        struct node *node=queue[front++];
        //print the node's data
        printf("%d ",node->data);
        //enqueue its left and right children if they exist
        if(node->left!=NULL){
            queue[rear++]=node->left;
        }
        if(node->right!=NULL){
            queue[rear++]=node->right;
        }
    }
}

int Height(struct node*node){
if(node==NULL){
return 0;
}
else{
int LHeight=Height(node->left);
int RHeight=Height(node->right);
if(LHeight>RHeight){
return(LHeight+1);
}
else{
return(RHeight+1);
}
}
}

void DisplayLeafNodes(struct node *root){
if(root==NULL){
return;
}
if(root->left ==NULL&&root->right==NULL){
printf("%d ",root->data);
}
DisplayLeafNodes(root->left);
DisplayLeafNodes(root->right);
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Binary search tree in level order: ");
    DisplayLevel(root);
    printf("\n");

    printf("height : %d\n", Height(root));

    printf("Leaf nodes of the binary search tree: ");
    DisplayLeafNodes(root);
    printf("\n");

    

    printf("Deleting node with data value 20: ");
    root = delete(root, 20);
    printf("\n");

    printf("Binary search tree in level order after deletion: \n");
    DisplayLevel(root);

    printf("Mirror image of the binary search tree: ");
    root = mirror_image(root);
    DisplayLevel(root);
    printf("\n");


    return 0;
}