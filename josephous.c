#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int data;
    struct Queue * next;
    struct Queue * front, * rear;
};

struct Queue * getQueuenode(int data){
    struct Queue * newnode = (struct Queue *)malloc(sizeof(struct Queue));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct Queue * createQueue(){
    struct Queue * queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue * queue,int data){
    struct Queue * newnode = getQueuenode(data);
    if (queue->rear!=NULL)
    {
        queue->rear->next = newnode;
        queue->rear = newnode;
        return;
    }
    queue->front = queue->rear = newnode;
}

int dequeue(struct Queue * queue){
    if(queue->front == NULL){
        return -1;
    }
    struct Queue * temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

int joseph(int n, int k){
    struct Queue * queue = createQueue();
    for(int i=1; i<=n; i++){
        enqueue(queue,i);
    }
    while(queue->front!=queue->rear){
         for(int i=1; i<k; i++){
            enqueue(queue,dequeue(queue));
    }
    dequeue(queue);
  }
  int lastperson = dequeue(queue);
  free(queue);
  return lastperson;
}

int main() {
    int n, k;
    printf("Enter the total number of people: ");
    scanf("%d", &n);
    printf("Enter the elimination pattern: ");
    scanf("%d", &k);

    int lastperson = joseph(n, k);
    printf("The last person standing is: %d", lastperson);

    return 0;
}
