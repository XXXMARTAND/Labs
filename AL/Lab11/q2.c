
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define INF 999
int mat[MAX][MAX];
int V;
int dist[MAX];
int q[MAX];
int qp = 0;
void enqueue(int v) 
{
	q[qp++] = v;
}

int cf(void *a, void *b) 
{
	int *x = (int *)a;
	int *y = (int *)b;
	return *y - *x;
}

int dequeue() 
{
	qsort(q, qp, sizeof(int), cf);
	return q[--qp];
}

int non_empty() 
{
	return (qp > 0);
}

int visited[MAX];
int vp = 0;

void dijkstra(int s) 
{
	dist[s] = 0;
	int i;
	for(i = 0; i < V; ++i) 
	{
		if (i != s) 
		{
			dist[i] = INF;
		}
		enqueue(i);
	}
	while(non_empty()) 
	{
		int u = dequeue();
		visited[vp++] = u;
		for(i = 0; i < V; ++i) 
		{
			if(mat[u][i]) 
			{
				if(dist[i] > dist[u] + mat[u][i]) 
				{
					dist[i] = dist[u] + mat[u][i];
				}
			}
		}
	}
}

int main() 
{
	printf("Enter no of vertices");
	scanf(" %d", &V);

	printf("\nEnter weight matrix \n");
	int i, j;
	for (i = 0; i < V; ++i) 
	{
		for (j = 0; j < V; ++j) 
		{
			scanf(" %d", &mat[i][j]);
		}
	}
	
	dijkstra(0);

	printf("\nStarting Node: 1\n");
	printf("\nNode\tDistance\n");
	
	for (i = 0; i < V; ++i)
	{
		printf("%d\t%d\n", i + 1, dist[i]);
	}
	
	return  0;
}