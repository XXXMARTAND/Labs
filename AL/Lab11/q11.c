#include <stdio.h>
#define MAX 30
typedef struct edge
{	
	int u, v, w;
} edge;
 
typedef struct list
{
	edge data[MAX];
	int n;
} list;
 
list elist;
int G[MAX][MAX], n;
list spanlist;
 
void sort()
{
	int i, j;
	edge temp;
	
	for(i = 1; i < elist.n; i++)
	{
		for(j = 0; j < elist.n - 1; j++)
		{
			if(elist.data[j].w > elist.data[j + 1].w)
			{
				temp = elist.data[j];
				elist.data[j] = elist.data[j + 1];
				elist.data[j + 1] = temp;
			}
		}
	}
}

int find(int belongs[], int vertexno)
{
	return(belongs[vertexno]);
}
 
void _union(int belongs[], int c1, int c2)
{
	int i;
	
	for(i = 0; i < n; i++)
	{
		if(belongs[i] == c2)
		{
			belongs[i] = c1;
		}
	}
}

void kruskal()
{
	int belongs[MAX], i, j, cno1, cno2;
	elist.n = 0;
 
	for(i = 1; i < n; i++)
	{
		for(j = 0; j < i; j++)
		{
			if(G[i][j] != 0 || G[i][j] != 999)
			{
				elist.data[elist.n].u = i;
				elist.data[elist.n].v = j;
				elist.data[elist.n].w = G[i][j];
				elist.n++;
			}
		}
	}
	sort();
	for(i = 0;i < n; i++)
		belongs[i] = i;
	spanlist.n = 0;
	for(i = 0; i < elist.n; i++)
	{
		c1 = find(belongs, elist.data[i].u);
		c2 = find(belongs, elist.data[i].v);
		
		if(c1 != c2)
		{
			spanlist.data[spanlist.n] = elist.data[i];
			spanlist.n = spanlist.n + 1;
			_union(belongs, c1, c2);
		}
	}
}

void print()
{
	int i, cost = 0;
	
	for(i = 0; i < spanlist.n; i++)
	{
		printf("\n%d - %d : %d", spanlist.data[i].v + 1, spanlist.data[i].u + 1, spanlist.data[i].w);
		cost = cost + spanlist.data[i].w;
	}
 
	printf("\n\nCost of spanning tree = %d\n", cost);
}
 
void main()
{
	int i, j, total_cost;
	
	printf("Enter no of vertices ");
	scanf("%d", &n);
	
	printf("\nEnter weight matrix \n");
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d", &G[i][j]);
		}
	}
			
	kruskal();
	print();
}