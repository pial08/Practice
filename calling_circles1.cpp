#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <stack>

#define MAX 100000

using namespace std;

bool edges[MAX][MAX];
bool edgesT[MAX][MAX];


map <string, int> m;
map <int, string> revmap;
stack <int> topsorted;

bool visited[MAX];
int node, edge;

int key = 1;

/*void dfs1(int src)
{
    visited[src] = true;

    for(int i = 1; i<=node; i++)
    {
        if(edges[src][i])
        {
            dfs1(i);
        }
    }
    topsorted.push(src);

}

void dfscall()
{
    for(int i=1;i<=node;i++)
    {
        if(!visited[i])
        {
            dfs1(i);
        }
    }
}

void dfs2(int src)
{
    visited[src] = true;
     cout << revmap[src] << " ";

    for(int i = 1; i<=node; i++)
    {
        if(edgesT[src][i])
        {
            dfs2(i);
        }
    }
}

void dfs2ndcall()
{
    while(!topsorted.empty())
    {
        int node = topsorted.top();
        topsorted.pop();
        //cout << "node " << node << " node\n";
        if(!visited[node])
        {
            dfs2(node);
            cout << endl;
        }
        topsorted.pop();
    }
}


void clearvar()
{
    for(int i=1;i<=node;i++)
    {
        visited[i] = false;
    }
}
*/





int main()
{
    freopen("input.txt", "r+", stdin);
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
            cout << m[x] << " " << m[y] << endl;
            //edges[m[x]].push_back(m[y]);

            //edgesT[m[y]].push_back(m[x]);

            edges[m[x]][m[y]] = true;
            edgesT[m[y]][m[x]] = true;








        }

        /*for(int i=1;i<=node;i++)
        {
            cout << revmap[i] << " ";
        }*/

        cout << endl;
        //dfscall();
        //clearvar();
        cout << endl << endl;

        //printstate();
        //cout << endl;


        //dfs2ndcall();

        /*for(int i=1;i<=node;i++)
        {
            edges[i].clear();
            edgesT[i].clear();
        }
        */
        m.clear();

        key = 1;

    }
    return 0;
}

