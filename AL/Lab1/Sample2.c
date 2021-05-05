
#include <stdio.h> 
#include <stdlib.h> 


struct AdjListNode 
{ 
	int dest; 
	struct AdjListNode* next; 
}; Z

struct AdjList 
{ 
	struct AdjListNode* head; 
}; 

struct Graph 
{ 
	int Ver; 
	struct AdjList* array; 
}; 

struct AdjListNode* newAdjListNode(int dest) 
{ 
	struct AdjListNode* newNode = 
	(struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
	newNode->dest = dest; 
	newNode->next = NULL; 
	return newNode; 
} 

struct Graph* createGraph(int V) 
{ 
	struct Graph* graph = 
		(struct Graph*) malloc(sizeof(struct Graph)); 
	graph->Ver = V; 

	graph->array = 
	(struct AdjList*) malloc(V * sizeof(struct AdjList)); 

	int i; 
	for (i = 0; i < V; ++i) 
		graph->array[i].head = NULL; 

	return graph; 
} 

void addEdge(struct Graph* graph, int src, int dest) 
{ 
	
	struct AdjListNode* newNode = newAdjListNode(dest); 
	newNode->next = graph->array[src].head; 
	graph->array[src].head = newNode; 

	newNode = newAdjListNode(src); 
	newNode->next = graph->array[dest].head; 
	graph->array[dest].head = newNode; 
} 

void printGraph(struct Graph* graph) 
{ 
	int v; 
	for (v = 0; v < graph->Ver; ++v) 
	{ 
		struct AdjListNode* pCrawl = graph->array[v].head; 
		printf("\n Adjacency list of vertex %d\n head ", v); 
		while (pCrawl) 
		{ 
			printf("-> %d", pCrawl->dest); 
			pCrawl = pCrawl->next; 
		} 
		printf("\n"); 
	} 
} 

int main() 
{ 
	
	struct Graph* graph = createGraph(V); 
	addEdge(graph, 0, 1); 
	addEdge(graph, 0, 4); 
	addEdge(graph, 1, 2); 
	addEdge(graph, 1, 3); 
	addEdge(graph, 1, 4); 
	addEdge(graph, 2, 3); 
	addEdge(graph, 3, 4); 


	printGraph(graph); 
	int adjMatrix[V][V];

    init(adjMatrix,V);
    addEdgeM(adjMatrix,0,1,V);
    addEdgeM(adjMatrix,0,2,V);
    addEdgeM(adjMatrix,0,3,V);
    addEdgeM(adjMatrix,1,3,V);
    addEdgeM(adjMatrix,1,4,V);
    addEdgeM(adjMatrix,2,3,V);
    addEdgeM(adjMatrix,3,4,V);

    printAdjMatrix(adjMatrix,V);


	return 0; 
} 


void init(int arr[][5], int V)
{
    int i,j;
    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            arr[i][j] = 0;
}


void addEdgeM(int arr[][5],int src, int dest, int V)
{
     arr[src][dest] = 1;
}

void printAdjMatrix(int arr[][5], int V)
{
     int i, j;

     for(i = 0; i < V; i++)
     {
         for(j = 0; j < V; j++)
         {
             printf("%d ", arr[i][j]);
         }
         printf("\n");
     }
}

