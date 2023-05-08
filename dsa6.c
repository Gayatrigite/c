#include <stdio.h>
#include <stdlib.h>
// Implementing Stack in LL
struct Node{
    int data;
    struct Node * next;
};
struct Node * top = NULL;
int isEmpty(struct Node * top){
    if(top == NULL){
        return 1;
    }
    return 0;
}
int isFull(struct Node * top){
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL){
        return 1;
    }
    return 0;
}
void traversal(struct Node * ptr){
    while(ptr!=NULL){
      printf("%d\n",ptr->data);
      ptr=ptr->next;
    }
}
struct Node * push(struct Node * top,int x){
    if(isFull(top)){
        printf("Stack overflow\n");
    }
    else{
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
int pop(struct Node * tp){
    if(isEmpty(tp)){
        printf("Stack underflow\n");
    }
    else{
        struct Node * n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}
int main(){
    top = push(top, 78);
    top = push(top, 8);
    top = push(top, 9);
    traversal(top);
    int element = pop(top);
    traversal(top);
}