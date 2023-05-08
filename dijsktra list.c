#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node {
    int dest;
    int weight;
    struct Node* next;
};

// Graph structure for adjacency list
struct Graph {
    int V; // number of vertices
    struct Node* adjList;
};

// Create a new node in the adjacency list
struct Node* createNode(int dest, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Create a graph using adjacency list
struct Graph createGraph(int V) {
    struct Graph graph;
    graph.V = V;
    graph.adjList = (struct Node*)malloc(V * sizeof(struct Node));
    for (int i = 0; i < V; i++) {
        graph.adjList[i].next = NULL;
    }
    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src].next;
    graph->adjList[src].next = newNode;
}

void main(){
    int n,v,p,src,dest,weight,min,index=1,i,j;
    printf("Enter the no of nodes: ");
    scanf("%d",&n);

    // Create graph using adjacency list
    struct Graph graph = createGraph(n);

    printf("Enter the edges and their weights: ");
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&src,&dest,&weight);
        addEdge(&graph,src,dest,weight);
    }

    printf("Enter the node to visit: ");
    scanf("%d",&v);

    printf("Enter the no of paths for the selected node: ");
    scanf("%d",&p);

    int path[p][n];

    printf("Enter the paths for the selected node: ");
    for(int i=0;i<p;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&path[i][j]);
        }
    }

    int distance[p];
    for(int i=0;i<p;i++){
        distance[i] = 0;
        int row = 1;
        for(int j=0;j<n-1;j++){
            if(row!=v){
                int column = path[i][j+1];
                struct Node* curr = graph.adjList + row;
                while(curr->next!=NULL){
                    curr = curr->next;
                    if(curr->dest==column){
                        distance[i] = distance[i] + curr->weight;
                        break;
                    }
                }
            }
            row = column;
        }
    }

    min=distance[0];
    for(i=1;i<p;i++){
        if(distance[i]<=min){
            min=distance[i];
            index=i;
        }
    }
    printf("min distance is %d\n",min);
    printf("min distance path is\n");
    for(i=0;i<n-1;i++){
        if(path[index][i]!=0){
            printf("--->%d",path[index][i]);
        }
    }
}
