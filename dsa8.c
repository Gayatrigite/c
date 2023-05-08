#include <stdio.h>
#include <stdlib.h>
struct queue{
    int size;
    int r;
    int f;
    int *arr;
};
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("Queue overloaded");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
    }
}
int dequeue(struct queue *q, int val){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is empty");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
void displayqueue(struct queue *q){
    for(int i=q->f+1;i<=q->r;i++){
        printf("%d\n",q->arr[i]);
    }
}
int main(){
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size*sizeof(int));
    enqueue(&q,12);
    enqueue(&q,15);
    displayqueue(&q);
    dequeue(&q,12);
    dequeue(&q,15);
}