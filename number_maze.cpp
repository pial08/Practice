#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>

#define MAX 1000
#define INF 9999999

using namespace std;

int maze[MAX][MAX];
int dist[MAX][MAX];
int row, col;

void printdist();


struct Node
{
    int x,y;
    int dist;

    Node(int _x, int _y, int _dist)
    {
        x = _x;
        y = _y;
        dist = _dist;
    }

    bool operator < (const Node & n) const
    {
        return dist > n.dist;
    }
};

int util[10][10] = {
                {1, 0},
                {0, 1},
                {-1, 0},
                {0, -1}
                };

priority_queue < Node > pq;



bool check(int x, int y)
{
    if(x >= 0 && x < row && y >= 0 && y < col)
        return true;
    return false;
}


void dijkstra(Node src)
{

    dist[src.x][src.y] = 0;

    pq.push(src);

    int x,y;

    while(!pq.empty())
    {
        Node u = pq.top();
        pq.pop();
        for(int i=0;i<4;i++)
        {
            x = u.x + util[i][0];
            y = u.y + util[i][1];
            //cout << x << " " << y << endl;


            if(check(x, y))
            {
                //cout << "iiqra";
                //cout << maze[u.x][u.y] << " # " <<  maze[x][y] << endl;
                if(maze[u.x][u.y] + maze[x][y] < dist[x][y])
                {
                    dist[x][y] = maze[u.x][u.y] + maze[x][y];
                    maze[x][y] = dist[x][y];
                    pq.push(Node(x,y,dist[x][y]));
                    //cout << x << " " << y << endl;


                //printdist();
                }

            }

        }
        //cout << "****************\n";
    }




}

void printdist()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
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

void clearvar()
{
    memset(maze, 0, sizeof(maze));
    memset(dist, 0, sizeof(dist));

}

int main()
{
    //freopen("input.txt", "r+", stdin);

    int n;
    cin >> n;
    while(n--)
    {


        cin >> row >> col;

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                int val;
                cin >> val;
                maze[i][j] = val;
                dist[i][j] = INF;
            }
        }

        Node node(0,0,INF);
        //node.x = 0;
        //node.y = 0;
        //node.dist = INF;
        if(row == 1 && col == 1)
        {
            cout << maze[row-1][col-1] << endl;
        }
        else
        {
            dijkstra(node);
            cout << dist[row-1][col-1] << endl;
        }

        clearvar();
        //printdist();



    }

    return 0;
}
