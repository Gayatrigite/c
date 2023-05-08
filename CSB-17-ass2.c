// Write a program to implement following operations on Singly Linked List - Create Insert Delete Display Reverse

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
    int i = 0;
    while(i!=index-1){
        p = p->next;
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

struct Node * deleteAtfirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node * deleteAtend(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next!=NULL){   // q last node
        p=p->next;          // p last second node
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct Node * deleteAtindex(struct Node * head,int index){
    struct Node * p = head;
    struct Node * q = head->next;
    for(int i=0; i<index-1; i++){
        p=p->next;
        q=q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node * reverse(struct Node * head){
    struct Node * prev = NULL;
    struct Node * nextnode = NULL;
    while(head!=NULL){
        nextnode = head->next;
        head->next = prev;
        prev = head;
        head = nextnode;
    }
    head = prev;
    return head;
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    //allocate memeory for nodes in linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;
    second->data=11;
    second->next=third;
    third->data=66;
    third->next=fourth;
    fourth->data=95;
    fourth->next=NULL;

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
    printf("delete at first\n");
    head = deleteAtfirst(head);
    traversal(head);
    printf("delete at index\n");
    head = deleteAtindex(head,2);
    traversal(head);
    printf("delete at end\n"); 
    head = deleteAtend(head);
    traversal(head);

    // printf("Reversing linked list\n");
    // head = reverse(head);
    // traversal(head);
}
