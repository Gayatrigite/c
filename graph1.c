#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//QUEUE OPERATIONS
int queue[100];
int rear=-1;
int front=0;
int queue_count=0;
void enqueue(int data){
    queue[++rear]=data;
    queue_count++;

}
int dequeue(){
    queue_count--;
    return queue[front++];
}

bool isqueueEmpty(){
    return queue_count>0 ? false:true;
}

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* create(int n){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = n;
    temp->next = NULL;
    return temp;
}

struct Node* insert(struct Node* head, int data){
    if(head == NULL){
        head = create(data);
        return head;
    }
    struct Node* temp = create(data);
    temp->next = head;
    return temp;
}

void print(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void BFS(int node, struct Node* G[], int visited[]){
    if(visited[node] == 0){
        visited[node] = 1;
        enqueue(node);
        while(!isqueueEmpty()){
            int val = dequeue();
            printf("%d ", val);
            struct Node* temp = G[val];
            while(temp != NULL){
                int i = temp->data;
                if(visited[i]==0){
                    enqueue(i);
                    visited[i] = 1;
                }
                temp = temp->next;
            }
        }
    }
}

void DFS(int node, struct Node* G[], int visited[]){
    if(visited[node] == 0){
        visited[node] = 1;
        printf("%d ", node);
        struct Node* temp = G[node];
        while(temp != NULL){
            int i = temp->data;
            if(visited[i]==0){
                DFS(i, G, visited);
            }
            temp = temp->next;
        }
    }
}

int main(){
    int n;
    printf("How many nodes are present ?\n");
    scanf("%d", &n);
    int visited[n];
    struct Node* G[n];
    for(int i = 0; i<n; ++i){
        printf("How many edges connected to node %d - ", i);
        int edges;
        scanf("%d", &edges);
        G[i] =  NULL;
        for(int j=0; j<edges; ++j){
            printf("Edge %d -> (0 - %d) - ", i, n-1);
            int e;
            scanf("%d", &e);
            G[i] = insert(G[i], e);
        }
        visited[i] = 0;
    }
    for(int i=0; i<n; ++i){
        printf("%d -> [ ", i);
        print(G[i]);
        printf("]\n");
    }
    for(int i=0; i<n; ++i){
        // DFS(i, G, visited);
        BFS(i, G, visited);
    }
    return 0;
}