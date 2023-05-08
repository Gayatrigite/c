//WAP to implement linear and circular queue using array and linked lists

// #include <stdio.h>
// #include <stdlib.h>

// struct queue{
//     int f;
//     int r;
//     int size;
//     int *arr;
// };
 
// int isFull(struct queue *q){
//     if(q->r == q->size-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// int isEmpty(struct queue *q){
//     if(q->r == q->f){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// void enqueue(struct queue * q,int val){
//     if(isFull(q)){
//         printf("Queue overflow");
//     }
//     else{
//         q->r++;
//         q->arr[q->r] = val;
//     }
// }

// int dequeue(struct queue * q,int val){
//     int a = -1;
//     if(isEmpty(q)){
//         printf("Queue is empty");
//     }
//     else{
//         q->f++;
//         a = q->arr[q->f];
//     }
//     return a;
// }

// void displayqueue(struct queue *q){
//     for(int i=q->f+1;i<=q->r;i++){
//         printf("%d\n",q->arr[i]);
//     }
// }

// int main(){
//     struct queue q;
//     q.size = 100;
//     q.f = q.r = -1;
//     q.arr = (int *)malloc(q.size*sizeof(int));
//     enqueue(&q,12);
//     enqueue(&q,15);
//     displayqueue(&q);
//     dequeue(&q,12);
//     dequeue(&q,15);
// }

// Linked List

// #include <stdio.h>
// #include <stdlib.h>
 
// struct Node *f = NULL;
// struct Node *r = NULL;
 
// struct Node
// {
//     int data;
//     struct Node *next;
// };
 
// void linkedListTraversal(struct Node *ptr)
// {
//     printf("Printing the elements of this linked list\n");
//     while (ptr != NULL)
//     {
//         printf("Element: %d\n", ptr->data);
//         ptr = ptr->next;
//     }
// }
 
// void enqueue(int val)
// {
//     struct Node *n = (struct Node *) malloc(sizeof(struct Node));
//     if(n==NULL){
//         printf("Queue is Full");
//     }
//     else{
//         n->data = val;
//         n->next = NULL;
//         if(f==NULL){
//             f=r=n;
//         }
//         else{
//             r->next = n;
//             r=n;
//         }
//     }
// }
 
// int dequeue()
// {
//     int a = -1;
//     struct Node *ptr = f;
//     if(f==NULL){
//         printf("Queue is Empty\n");
//     }
//     else{
//         f = f->next; 
//         a = ptr->data;
//         free(ptr);
//     }
//     return a;
// }
 
// int main()
// {
//     linkedListTraversal(f);
//     enqueue(34);
//     enqueue(4);
//     enqueue(7);
//     enqueue(17);
//     printf("Dequeuing element %d\n", dequeue());
//     printf("Dequeuing element %d\n", dequeue());
//     printf("Dequeuing element %d\n", dequeue());
//     printf("Dequeuing element %d\n", dequeue());
//     linkedListTraversal(f);
//     enqueue(5);
//     printf("Dequeuing element %d\n", dequeue());
//     return 0;
// }


//circular

// #include<stdio.h>
// #include<stdlib.h>
 
// struct circularQueue
// {
//     int size;
//     int f;
//     int r;
//     int* arr;
// };
 
 
// int isEmpty(struct circularQueue *q){
//     if(q->r==q->f){
//         return 1;
//     }
//     return 0;
// }
 
// int isFull(struct circularQueue *q){
//     if((q->r+1)%q->size == q->f){
//         return 1;
//     }
//     return 0;
// }
 
// void enqueue(struct circularQueue *q, int val){
//     if(isFull(q)){
//         printf("This Queue is full");
//     }
//     else{
//         q->r = (q->r +1)%q->size;
//         q->arr[q->r] = val; 
//         printf("Enqued element: %d\n", val);
//     }
// }
 
// int dequeue(struct circularQueue *q){
//     int a = -1;
//     if(isEmpty(q)){
//         printf("This Queue is empty");
//     }
//     else{
//         q->f = (q->f +1)%q->size;
//         a = q->arr[q->f]; 
//     }
//     return a;
// }
 
 
// int main(){
//     struct circularQueue q;
//     q.size = 4;
//     q.f = q.r = 0;
//     q.arr = (int*) malloc(q.size*sizeof(int));
    
//     // Enqueue few elements
//     enqueue(&q, 12);
//     enqueue(&q, 15);
//     enqueue(&q, 1); 
//     printf("Dequeuing element %d\n", dequeue(&q));
//     printf("Dequeuing element %d\n", dequeue(&q));
//     printf("Dequeuing element %d\n", dequeue(&q)); 
//     enqueue(&q, 45);
//     enqueue(&q, 45);
//     enqueue(&q, 45);
 
//     if(isEmpty(&q)){
//         printf("Queue is empty\n");
//     }
//     if(isFull(&q)){
//         printf("Queue is full\n");
//     }
 
//     return 0;
// }

//linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue (int d)			//Insert elements in Queue
{
  struct node *n;
  n = (struct node *) malloc (sizeof (struct node));
  n->data = d;
  n->next = NULL;
  if ((r == NULL) && (f == NULL))
    {
      f = r = n;
      r->next = f;
    }
  else
    {
      r->next = n;
      r = n;
      n->next = f;
    }
}

void dequeue ()			// Delete an element from Queue
{
  struct node *t;
  t = f;
  if ((f == NULL) && (r == NULL))
    printf ("\nQueue is Empty");
  else if (f == r)
    {
      f = r = NULL;
      free (t);
    }
  else
    {
      f = f->next;
      r->next = f;
      free (t);
    }


}

void display ()
{				// Print the elements of Queue
  struct node *t;
  t = f;
  if ((f == NULL) && (r == NULL))
    printf ("\nQueue is Empty");
  else
    {
      do
	{
	  printf (" %d", t->data);
	  t = t->next;
	}
      while (t != f);
    }
}

int main ()
{
  enqueue (34);
  enqueue (22);
  enqueue (75);
  enqueue (99);
  enqueue (27);
  printf ("Circular Queue: ");
  display ();
  printf ("\n");

  dequeue ();
  printf ("Circular Queue After dequeue: ");
  display ();
  return 0;
}
