#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100 // Maximum size of the queue
#define MAX_STACK_SIZE 100
int no_vertices;
void printgraph(int adj[][no_vertices]);

// Breadth First Search function
void BFS(int adj[][no_vertices], int start_vertex) {
    bool visited[no_vertices]; // array to keep track of visited vertices
    for(int i = 0; i < no_vertices; i++) {
        visited[i] = false; // mark all vertices as unvisited initially
    }

    // create a queue to store the vertices
    int queue[MAX_QUEUE_SIZE];
    int front = -1, rear = -1;
    queue[++rear] = start_vertex;
    visited[start_vertex] = true;

    printf("\nBFS traversal starting from vertex %d: ", start_vertex);

    while (front != rear) { // while the queue is not empty
        int current_vertex = queue[++front];  //This line dequeues the next vertex from the queue, by incrementing the front pointer and retrieving the element at that position in the queue.
        printf("%d ", current_vertex);  //This line prints the value of the current vertex that was just dequeued.

        // add all unvisited neighbors of the current vertex to the queue
        for(int i = 0; i < no_vertices; i++) {
            if(adj[current_vertex][i] == 1 && !visited[i]) {  //This line checks if the current vertex has an edge connecting it to the vertex at index i, and whether that vertex has been visited already or not. If both conditions are met, the vertex at index i is added to the end of the queue, and marked as visited.
                queue[++rear] = i;   //This line adds the vertex at index i to the end of the queue, by incrementing the rear pointer and setting the element at that position in the queue to the value of i.
                visited[i] = true;   //This line marks the vertex at index i as visited, to avoid revisiting it again later.
            } 
        }
    }
}


// Depth First Search function
void DFS(int adj[][no_vertices], int start_vertex) {
    bool visited[no_vertices]; // array to keep track of visited vertices
    for(int i = 0; i < no_vertices; i++) {
        visited[i] = false; // mark all vertices as unvisited initially
    }

    // create a stack to store the vertices
    int stack[MAX_STACK_SIZE];
    int top = -1;
    stack[++top] = start_vertex;
    visited[start_vertex] = true;

    printf("\nDFS traversal starting from vertex %d: ", start_vertex);

    while (top != -1) { // while the stack is not empty
        int current_vertex = stack[top--];  //This line pops the top vertex from the stack, by retrieving the element at the top position and decrementing the top pointer.
        printf("%d ", current_vertex);  //This line prints the value of the current vertex that was just popped.

        // add all unvisited neighbors of the current vertex to the stack
        for(int i = 0; i < no_vertices; i++) {
            if(adj[current_vertex][i] == 1 && !visited[i]) {  //This line checks if the current vertex has an edge connecting it to the vertex at index i, and whether that vertex has been visited already or not. If both conditions are met, the vertex at index i is pushed onto the stack, and marked as visited.
                stack[++top] = i;   //This line pushes the vertex at index i onto the stack, by incrementing the top pointer and setting the element at that position in the stack to the value of i.
                visited[i] = true;   //This line marks the vertex at index i as visited, to avoid revisiting it again later.
            } 
        }
    }
}
// function to print the adjacency matrix
void printgraph(int adj[][no_vertices]){
    printf("\nThe adjacency matrix of the graph is:\n");
    for(int i=0;i<no_vertices;i++){
        for(int j=0;j<no_vertices;j++){
            printf(" %d ",adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int source = 0, destination = 0;
    printf("\nEnter the number of vertices : ");
    scanf("%d",&no_vertices);
    int adj[no_vertices][no_vertices];

    for(int i=0; i<no_vertices; i++)
        for(int j=0; j<no_vertices; j++)
            adj[i][j] = 0; // initialize adjacency matrix to 0

    // take input of edges
    while (source!=-1 && destination!=-1) {
        printf("Enter an edge from node(0 to %d) to node(0 to %d) : ",no_vertices-1,no_vertices-1);
        scanf("%d%d",&source,&destination);
        if(source!=-1 && destination!=-1){
            adj[source][destination] = 1;
            adj[destination][source] = 1; //graph is undirected, meaning that the edge can be traversed in both directions
        }
    }
    printgraph(adj); // print the adjacency matrix

    int start_vertex;
    printf("\nEnter the starting vertex for BFS: ");
    scanf("%d", &start_vertex);
    BFS(adj, start_vertex); // call BFS function with start vertex
    DFS(adj, start_vertex);
    return 0;
}