#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
#define MAX 100000
 //********************************** unfinished ****************************************************//

using namespace std;

map <string, int> m;
map <int, string> revmap;
stack <int> topsorted;

vector <int> edges[MAX];
vector <int> edgesT[MAX];
bool visited[MAX];
int node, edge;

int key = 1;

void dfsT(int src)
{
    visited[src] = true;
    cout << revmap[src] ;

    for(int i=0;i<edgesT[src].size();i++)
    {
        int node = edgesT[src][i];
        if(!visited[node])
        {
            cout << ", ";
            dfsT(node);
            //cout << revmap[node] << " ";

        }
    }
    //topsorted.push(src);

}


void dfs(int src)
{
    visited[src] = true;

    //cout << revmap[src] << " ";
    for(int i=0;i<edges[src].size();i++)
    {
        int node = edges[src][i];
        //cout << node << "dfs " << visited[node] << " \n";

        if(!visited[node])
        {
            //cout << "entered " << revmap[node];

            dfs(node);
        }
    }
    topsorted.push(src);

}

void dfs2ndcall()
{
    int count = 0;
    while(!topsorted.empty())
    {
        int node = topsorted.top();
        topsorted.pop();
        //cout << revmap[node] << " ";
        if(!visited[node])
        {
            //cout << revmap[node];
            dfsT(node);

            cout << endl;
            //cout << revmap[node] << " *";
        }
        //topsorted.pop();

    }
    //cout << endl;
}

void dfscall()
{
    //cout << visited[5] << "visited\n";
    for(int i=1;i<=node;i++)
    {

        if(!visited[i])
        {
            //cout << i << " at dfscall\n";
            dfs(i);
        }
    }
}

void clearvar()
{
    for(int i=1;i<=node;i++)
    {
        visited[i] = false;
    }
}




int main()
{
    //freopen("input.txt", "r+", stdin);
    int counter = 1;
    while(true)
    {

        string x, y;
        cin >> node >> edge;
        if(node == 0 && edge ==0)
            break;

        for(int i=0;i<edge;i++)
        {
            cin >> x >> y;
            if(m[x] == 0)
            {
                m[x] = key;
                revmap[key] = x;
                key++;
            }
            if(m[y] == 0)
            {
                m[y] = key;
                revmap[key] = y;
                key++;
            }
            //cout << m[x] << " " << m[y] << endl;
            edges[m[x]].push_back(m[y]);

            edgesT[m[y]].push_back(m[x]);








        }

        /*for(int i=1;i<=node;i++)
        {
            cout << revmap[i] << " ";
        }*/

        //cout << endl;
        dfscall();
        clearvar();


        cout << "Calling circles for data set " << counter++ << ":" << endl;
        dfs2ndcall();
        //cout << "finished\n";
        for(int i=1;i<=node;i++)
        {
            edges[i].clear();
            edgesT[i].clear();
        }
        m.clear();
        revmap.clear();
        clearvar();
        //cout << endl;



        key = 1;

    }
    return 0;
}


/*
input data
7 8
1 2
2 3
3 1
3 4
4 5
5 6
6 7
7 5
*/
