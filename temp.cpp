#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <queue>

#define MAX 10000

using namespace std;

bool graph[MAX][MAX];
pair <int, int> src;
pair <int, int> dest;
int row, col;

map < pair<int, int> , bool > visited;
map < pair<int, int> , int > dist;
queue < pair <int, int> > q;
vector < pair <int, int> > v;

int util[10][10] = {
                {1, 0},
                {0, 1},
                {-1, 0},
                {0, -1}
                };


void printpair(pair < int, int > p )
{
    //cout << "pair is ";
    //cout << p.first << " " << p.second << endl;
}

bool check(int x, int y)
{
    if(x >= 0 && x < row && y >= 0 && y < col)
        return true;
    return false;
}

bool bfs(pair <int, int> src, pair <int, int> dest)
{
    visited[src] = true;
    dist[src] = 0;
    graph[src.first][src.second] = true;

    q.push(src);
    bool flag = false;

    while(!q.empty())
    {
        //cout << "*";
        pair <int, int> u;
        u = q.front();
        int x, y;
        printpair(u);

        vector < pair <int, int> > v;
        int boo;
        cin >> boo;
        //finding adjacent nodes
        for(int i=0;i<4;i++)
        {

            x = u.first + util[i][0];
            y = u.second + util[i][1];
            //cout << util[i][0] << " + " << util[i][1] << endl;
            //cout << x << " created " << y << endl;
            if(check(x, y))
                v.push_back(make_pair(x, y));
        }

        for(int i=0;i<v.size();i++)
        {
            pair <int, int> node = v[i];
            if(!graph[node.first][node.second]) // !visited[node]
            {
                //cout << "BOO\n";
                visited[node] = true;
                dist[node] = dist[u] + 1;
                graph[node.first][node.second] = true;

                q.push(node);

            }
        }
        v.clear();
        cout << "size of queue " << q.size() << endl;
        q.pop();



    }




}


void clearall()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            graph[i][j] = false;
        }
    }
    visited.clear();
    dist.clear();
    v.clear();
}

int main()
{

    freopen("input.txt", "r+", stdin);
    while(true)
    {
        cin >> row >> col;
        if(!row && !col)
            break;

        int n;
        cin >> n;
        while(n--)
        {
            int src;
            int loop;
            cin >> src >> loop;
            while(loop--)
            {
                int x;
                cin  >> x;
                graph[src][x] = true;

            }
        }
        int x, y;
        cin >> x >> y;
        src = make_pair(x, y);
        cin >> x >> y;
        dest = make_pair(x, y);
        bfs(src, dest);

        cout << dist[dest] << endl;

        clearall();
    }

    return 0;
}
