#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <queue>
#include <cstring>

#define MAX 1000

using namespace std;

bool graph[MAX][MAX];
pair <int, int> src;
pair <int, int> dest;
int dist[MAX][MAX];
int row, col;

//map < pair<int, int> , bool > visited;
//map < pair<int, int> , int > dist;
queue < pair <int, int> > q;

int util[10][10] = {
                {1, 0},
                {0, 1},
                {-1, 0},
                {0, -1}
                };




bool check(int x, int y)
{
    if(x >= 0 && x < row && y >= 0 && y < col)
        return true;
    return false;
}

bool bfs(pair <int, int> src, pair <int, int> dest)
{
    //visited[src] = true;
    dist[src.first][src.second] = 0;
    graph[src.first][src.second] = true;

    q.push(src);
    //bool flag = false;

    while(!q.empty())
    {
        pair <int, int> u;
        u = q.front();
        int x, y;

        for(int i=0;i<4;i++)
        {

            x = u.first + util[i][0];
            y = u.second + util[i][1];

            if(check(x, y))
            {
                //v.push_back(make_pair(x, y));
                pair <int, int> node = make_pair(x, y);
                if(!graph[x][y]) // !visited[node]
                {

                    dist[node.first][node.second] = dist[u.first][u.second] + 1;

                    graph[x][y] = true;

                    q.push(node);

                }
            }
        }
        q.pop();
    }
}


void clearall()
{
    /*for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            graph[i][j] = false;

        }
    }*/
    //visited.clear();
    //dist.clear();
    memset(graph, 0, sizeof(graph));
    memset(dist, 0, sizeof(dist));

    //v.clear();
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

        cout << dist[dest.first][dest.second] << endl;

        clearall();
    }

    return 0;
}
