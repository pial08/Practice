#include<stdio.h>
#include<limits.h>
#include<iostream>

#define INF 99999
#define V 4
using namespace std;
void printGraph();
int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
int dist[V][V];

int floyed()
{
	
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			dist[i][j] = graph[i][j];	
		}
	}
	printGraph();
	for(int k=0;k<V;k++)
	{
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				if(dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];	
				}
			}
		}
	}
	
}

void printGraph()
{
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			if(dist[i][j] == INF)
				cout << "INF ";
			else 
				cout << dist[i][j] << " ";

		}
		cout << endl;
	}
	cout << endl;
}


int main()
{
	//cout << INF;
	
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			if(graph[i][j] == INF)
				cout << "INF ";
			else 
				cout << graph[i][j] << " ";

		}
		cout << endl;
	}
	cout << endl;
    floyed();
    printGraph();
	return 0;
}
