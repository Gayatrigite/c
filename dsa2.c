#include <stdio.h>
#include <stdlib.h>
// Deletion on LinkedList
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
struct Node * deletefirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct Node * deleteatindex(struct Node * head,int index){
    struct Node * p = head;
    struct Node * q = head->next;
    for(int i=0;i<index-1;i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct Node * deleteatend(struct Node * head){
   struct Node * p = head;
   struct Node * q = head->next; 
   while(q->next!=NULL){ //q last node
    p = p->next;
    q = q->next;
   }
   p->next=NULL;   // p is last second node
   free(q);
   return head;
}
struct Node * deleteatvalue(struct Node * head,int value){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next!=NULL && q->data!=value){
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
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
    printf("delete at first\n");
    head = deletefirst(head);
    traversal(head);
    printf("delete at index\n");
    head = deleteatindex(head,2);
    traversal(head);
    printf("delete at end\n"); 
    head = deleteatend(head);
    traversal(head);
    printf("delete at value\n");
    head = deleteatvalue(head,66);
    traversal(head);
}   