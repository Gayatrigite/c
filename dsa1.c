#include <stdio.h>
#include <stdlib.h>
//LinkedList creation and traversal and insertion
struct Node{
    int data;
    struct Node * next;
};

void traversal(struct Node * ptr){
    while(ptr!=NULL){
      printf("%d\n",ptr->data);
      ptr=ptr->next;
    }
}

struct Node * insertAtfirst(struct Node * head,int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct Node * insertAtindex(struct Node * head,int data,int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++; 
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node * insertAtend(struct Node * head,int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    ptr->data=data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;

    //allocate memeory for nodes in linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;
    second->data=11;
    second->next=third;
    third->data=66;
    third->next=NULL;

    traversal(head);
    printf("insert at first\n");
    head = insertAtfirst(head,56);
    traversal(head);
    printf("insert at index\n");
    head = insertAtindex(head,74,1);
    traversal(head);
    printf("insert at end\n");
    head = insertAtend(head,54);
    traversal(head);
}