#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXQUEUESIZE 100
#define MAXSTACKSIZE 100

int no_vertices;
void printgraph(int adj[][no_vertices]);

void bfs(int adj[][no_vertices],int start_vertex){
    bool visited[no_vertices];
    for(int i=0;i<no_vertices;i++){
        visited[i]=false;
    }
    int queue[MAXQUEUESIZE];
    int front=-1,rear=-1;
    queue[++rear]=start_vertex;
    visited[start_vertex]=true;

    printf("BFS traversal starts from vertex %d \n",start_vertex);

    while(front!=rear){
        int current_vertex=queue[++front];
        printf("%d ",current_vertex);

        for(int i=0;i<no_vertices;i++){
            if(adj[current_vertex][i]==1 && !visited[i]){
                queue[++rear]=i;
                visited[i]=true;
            }
        }
    }
}
void dfs(int adj[][no_vertices],int start_vertex){
    bool visited[no_vertices];
    for(int i=0;i<no_vertices;i++){
        visited[i]=false;
    }
    int stack[MAXSTACKSIZE];
    int top=-1;
    stack[++top]=start_vertex;
    visited[start_vertex]=true;
    printf("\nDFS traversal starts from vertex %d ",start_vertex);

    while(top!=-1){
        int current_vertex=stack[top--];
        printf("%d ",current_vertex);

        for(int i=0;i<no_vertices;i++){
            if(adj[current_vertex][i] && !visited[i]){
                stack[++top]=i;
                visited[i]=true;
            }
        }
    }
}
void printgraph(int adj[][no_vertices]){
    printf("The adj matrix is \n");
    for(int i=0;i<no_vertices;i++){
        for(int j=0;j<no_vertices;j++){
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int source=0,destination=0;
    printf("enter the no of vertices ");
    scanf("%d",&no_vertices);
    int adj[no_vertices][no_vertices];

    for(int i=0;i<no_vertices;i++)
        for(int j=0;j<no_vertices;j++)
            adj[i][j]=0;
    
    while(source!=-1 && destination!=-1){
        printf("enter the edge from (0 to %d) to (0 to %d)",no_vertices-1,no_vertices-1);
        scanf("%d%d",&source,&destination);
        if(source!=-1 && destination!=-1){
            adj[source][destination]=1;
            adj[destination][source]=1;
        }
    }
    printgraph(adj);

int start_vertex;
    printf("enter the start vertex ");
    scanf("%d",&start_vertex);
    bfs(adj,start_vertex);
    dfs(adj,start_vertex);
}