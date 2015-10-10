#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define V 4
#define INF 99999
using namespace std;
void print(int x[][V]);
void warshall(int graph[][V])
{
	int dist[V][V];
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			dist[i][j] = graph[i][j];
		}
	}

	for(int k = 0; k < V; k++)
		for(int i = 0; i < V; i++)
			for(int j = 0; j < V; j++) {
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
	print(dist);
}

void print(int x[][V])
{
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if(x[i][j] == INF) 
				printf("%7s", "INF");
			else 
				printf("%7d", x[i][j]);
		}
		cout << endl;
	}
}

int main() { _
	int graph[V][V] = {{0, 5, INF, 10},
					   {INF, 0, 3, INF},
					   {INF, INF, 0, 1},
					   {INF, INF, INF, 0}};	
	warshall(graph);
	return 0;
}