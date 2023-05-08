// #include <stdio.h>
// #include <stdlib.h>

// struct queue{
//     int f;
//     int r;
//     int size;
//     int *arr;
// };
// int full(struct queue *q){
//     if(q->r == q->size-1){
//         return 1;
//     }
//     return 0;
// }
// int empty(struct queue *q){
//     if(q->f==q->r){
//         return 1;
//     }
//     return 0;
// }
// void enqueue(struct queue *q,int data){
//     if(full(q)){
//         printf("can't enqueue");
//     }
//     else{
//     q->r++;
//     q->arr[q->r]=data;
// }
// }
// int dequeue(struct queue *q,int data){
//     int a=-1;
//     if(empty(q)){
//         printf("can't dequeue");
//     }
//     else{
//     q->f++;
//     a=q->arr[q->f];
// }
// return a;
// }
// void display(struct queue *q){
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
//     display(&q);
//     dequeue(&q,12);
//     dequeue(&q,15);
// }

#include <stdio.h>
#include <stdlib.h>
struct queue{
    int f;
    int r;
    int size;
    int *arr;
};
int full(struct queue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    else{
        return 0;
    }
}
int empty(struct queue *q){
    if(q->f==q->r){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct queue *q,int val){
    if(full(q)){
        printf("can't enqueue");
    }
    else{
    q->r=(q->r+1)%q->size;
    q->arr[q->r]=val;
    printf("enqueued element %d\n",val);
    }
}
int dequeue(struct queue *q){
    int a=-1;
    if(empty(q)){
        printf("can't dequeue");
    }
    else{
    q->f=(q->f+1)%q->size;
    a=q->arr[q->f];
    }
    return a;
}
int main(){
    struct queue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q)); 
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);
    return 0;
}
