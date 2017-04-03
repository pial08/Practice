#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int V;
int E;
int dist[1000];
bool visited[1000];
int parent[1000];
queue<int> q;
stack<int> path;
stack<int> topsort;

int cycleB, cycleE;


vector<int> edges[100];
bool cycle[1000];
int tm = 0;
int finish[1000];

void printPath(int src, int dest)
{

    if(src!=dest)
    {
        printPath(src,parent[dest]);
    }
    cout << dest << " ";

}

void dfs(int src)
{
    visited[src] = true;
    tm++;
    dist[src] = tm;
    cycle[src] = true;

    //parent[src] = src;
    cout << src << " ";
    for(int i=0;i<edges[src].size();i++)
    {

        int node = edges[src][i];
        if(!visited[node])
        {
            //dist[node] = dist[src] + 1;
            parent[node] = src;
            //visited[node] = true;

            dfs(node);
        }
        /*else if(cycle[node])
        {
            cout << "cycle detected\n";
        }*/
        else if(cycle[node])
        {
            cout << "cycle detected " << src << " " << node << endl;
            //cout << parent[node];
            //printPath(src, node);
            cycleB = src;
            cycleE = node;
            cout << "cycle printed\n";

        }
    }

    cycle[src] = false;
    tm++;
    finish[src] = tm;
    topsort.push(src);
}



void dfsCall()
{
    for(int i=1;i<=V;i++)
    {
        cout << "pial\n";
        if(!visited[i])
        {
            dfs(i);
        }
    }
}

void bfs(int src)
{
    dist[src] = 0;
    //parent[src] = src;
    visited[src] = true;
    q.push(src);
    //cout << "pial\n";
    while(!q.empty())
    {
        //cout << "inside while\n";
        int u = q.front();
        for(int i=0;i<edges[u].size();i++)
        {
            //cout << "inside for\n";
            int node = edges[u][i];
            cout << u << " ";
            if(!visited[node])
            {
                q.push(node);
                //visited[node] = true;
                parent[node] = u;
                dist[node] = dist[u] + 1;
            }


        }
        q.pop();
        cout << endl;
    }




}


int main()
{
    freopen("final.txt", "r", stdin);

    cin >> V >> E;
    //cout << V << " " << E;
    //edges[1].push_back(4);

    for(int i=1;i<=E;i++)
    {
        int x,y;
        cin >> x >> y;
        edges[x].push_back(y);
    }
    int src, dest;
    cin >> src >> dest;

    bfs(src);

    for(int i=1;i<=V;i++)
    {
        for(int j=0;j<edges[i].size();j++)
        {
            //cout << edges[i][j] << " ";
        }
        cout << endl;
    }

    //dfsCall();
    //printPath(src,dest);

    //cout << "printing cycle from " << cycleE << " " << cycleB << endl;
    //printPath(cycleE, cycleB);


    /*cout << "start and end\n";
    for(int i=1;i<=V;i++)
    {
        cout << dist[i] << " " << finish[i] << endl;
    }
    cout << "Top sorted list\n";
    while(!topsort.empty())
    {
        cout<< topsort.top() << " ";

        topsort.pop();
    }
    */
    return 0;
}
