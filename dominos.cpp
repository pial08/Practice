#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int dist[1000000];
bool visited[1000000];
stack<int> s;
vector<int> graph[1000000];
int node, edge;
//*******************  remember to clear all variables
//int tm = 0;

void dfs(int src)
{
    //tm++;
    //dist[src] = tm;
    //cout << src << " ";
    visited[src] = true;

    for(int i=0;i<graph[src].size();i++)
    {
        int node = graph[src][i];
        if(!visited[node])
        {
            dfs(node);
        }
    }
    //tm++;
    s.push(src);
}

void clearvar(int node, int edge)
{
    for(int i=1;i<=node;i++)
    {
        dist[i] = 0;
        visited[i] = false;
    }

}

void printstate()
{
    for(int i=1;i<=node;i++)
    {
        cout << visited[i] << endl;
        for(int j=0;j<graph[i].size();j++)
        {
            cout << graph[i][j] << " ";

        }
        cout << endl;
    }
}



int main()
{
    int n;
    cin >> n;
    int counter = 0;


    while(n--)
    {

        cin >> node >> edge;

        for(int i=1;i<=edge;i++)
        {
            int x,y;
            cin >> x >> y;
            graph[x].push_back(y);
        }

        for(int i=1;i<=node;i++)
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }
        //cout << endl;

        clearvar(node, edge);
        counter = 0;
        while(!s.empty())
        {
            int node = s.top();
            //cout << node << " kochu\n";
            if(!visited[node])
            {
                counter++;
                dfs(node);
            }
            s.pop();
        }

        //printstate();

        cout << counter << endl;

        for(int i=1;i<=node;i++)
        {
            graph[i].clear();
        }
        //cout << "final clearing\n";
        clearvar(node, edge);
        //printstate();





    }
    return 0;
}
