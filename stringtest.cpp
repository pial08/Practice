#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

string dec2bin(int num)
{
    if(num == 0)    return "0";
    if(num == 1)    return "1";

    if(num % 2 == 0)    return dec2bin(num/2) + "0";
    return dec2bin(num/2) + "1";
}

bool visited[100];
int dist[100];
int parent[100];
vector <int> edges[100];
queue <int> q;

void bfs(int src)
{
    visited[src] = true;
    dist[src] = 0;
    parent[src] = src;

    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
        for(int i=0;i<edges[u].size();i++)
        {
            int node = edges[u][i];
            if(!visited[node])
            {
                visited[node] = true;
                dist[node] = dist[u] + 1;
                parent[node] = u;
                q.push(node);
            }
        }
        q.pop();

    }

}

void printpath(int src, int dest)
{
    if(src != dest)
    {
        printpath(src, parent[dest]);

    }
    cout << dest << " ";
}

string rev(string str)
{
    int len = str.size();
    for(int i=0;i<len/2;i++)
    {
        swap(str[i], str[(len-1)-i]);
    }
    return str;
}

int main ()
{
  /*string str="We think in generalities, but we live in details.";
                                           // (quoting Alfred N. Whitehead)

  string str2 = str.substr (3,5);     // "think"

  size_t pos = str.find("live");      // position of "live" in str
  //cout << pos << " " << str2 << endl;

  string str3 = str.substr (pos);     // get from "live" to the end

  cout << str2 << ' ' << str3 << '\n';
  cout << dec2bin(504);*/

    string p;
    p = "pial";
    char c = p[0];

    cout << rev("ABCD");
    //cout << p.size();
    int node, edge;
    freopen("final.txt", "r+", stdin);

    cin >> node >> edge;


    for(int i=0;i<edge;i++)
    {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
    }
    int src, dest;
    cin >> src >> dest;
    bfs(src);

    printpath(src, dest);

  return 0;
}
