//SLL create insert delete reverse
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};
void traversal(struct node * ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct node * insertatfirst(struct node * head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}
struct node * insertatend(struct node* head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node * p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
struct node *insertatindex(struct node *head,int data,int index){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node * p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;   
    return head;
}
struct node *deleteatfirst(struct node*head){
    struct node*ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct node*deleteatend(struct node *head){
    struct node*p=head;
    struct node *q=head->next;
    while (q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
struct node*deleteatindex(struct node *head,int index){
    struct node*p=head;
    struct node *q=head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
struct node *reverse(struct node *head){
    struct node *prev=NULL;
    struct node *nextnode=NULL;
    while(head!=NULL){
    nextnode=head->next;
    head->next=prev;
    prev=head;
    head=nextnode;
    }
    head=ptr;
    return head;
}
int main(){
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;

    //allocate memeory for nodes in linked list in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

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
    head = insertatfirst(head,56);
    traversal(head);
    printf("insert at index\n");
    head = insertatindex(head,74,1);
    traversal(head);
    printf("insert at end\n");
    head = insertatend(head,54);
    traversal(head);
    printf("delete at first\n");
    head = deleteatfirst(head);
    traversal(head);
    printf("delete at index\n");
    head = deleteatindex(head,2);
    traversal(head);
    printf("delete at end\n"); 
    head = deleteatend(head);
    traversal(head);

    // printf("Reversing linked list\n");
    //head = reverse(head);
    //traversal(head);
}
