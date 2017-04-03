#include <stdio.h>
#include <iostream>

using namespace std;

char matrix[100][100];
int row, col;

int m[4][4] = {{-1, 0},
                  {1, 0},
                  {0, -1},
                  {0, 1} };


bool check(int x, int y)
{
    if(x >=0 && x < row && y >= 0 && y < col)
        return true;
    return false;
}
void printmat()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int destx, desty;


void boo(int x, int y, int dir)
{
    int prevx, prevy;
    cout << x << " " <<  y << endl;
    while(true)
    {
        prevx = x;
        prevy = y;

        x = m[dir-1][0] + x;
        y = m[dir-1][1] + y;
        //cout << m[dir-1][0] << " chata " << m[dir-1][1] << endl;

        if(!check(x, y))
        {
            destx = prevx;
            desty = prevy;
            return;
        }
        cout << x << " " << y << endl;
        if(matrix[x][y] == '/')
        {
            if(prevx == x)
            {
                if((y - prevy) == 1)
                {
                    dir = 1;
                }
                else
                    dir = 2;

            }
            else if(prevy == y)
            {
                if( (x - prevx) == 1 )
                {
                    dir = 3;
                }
                else
                    dir = 4;
            }
        }
        if(matrix[x][y] == '\\')
        {
            if(prevx == x)
            {
                if((y - prevy) == 1)        // left 2 right
                {
                    dir = 2;
                }
                else                        // right 2 left
                    dir = 1;

            }
            else if(prevy == y)
            {
                if( (x - prevx) == 1 )      // top 2 bottom
                {
                    dir = 4;
                }
                else                        // bottom to top
                    dir = 3;
            }

        }
    }


}

int main()
{
    freopen("input3.txt", "r+", stdin);
    cin >> row >> col;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin >> matrix[i][j];
        }
    }

    int x, y;
    int dir;
    cin >> x >> y;
    cin >> dir;
    //cout << x << " " << y << " " << dir << endl;

    boo(x, y, dir);
    cout << destx << " " << desty << endl;



    //printmat();

}
