#include <stdio.h>
#include <iostream>
#include<limits.h>

using namespace std;

int mat[3][3] =   { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };





int min(int x, int y, int z)
{
    if(x < y && x < z)  return x;
    if(y < x && y < z)  return y;
    if(z < x && z < y)  return z;

}




int recurmincost(int xD, int yD, int x, int y)
{

    if(x > xD || y > yD)
        return INT_MAX;

    //cout << x << " " << y << endl;
    if(xD == x && yD == y)
    {
        //cout << "done one\n";
        return mat[x][y];
    }

    else
    {
        /*int val = min (recurmincost(xD, yD, x+1, y+1),
                       recurmincost(xD, yD, x+1, y),
                       recurmincost(xD, yD, x, y+1) );*/

        //cout << mat[x][y] + val << endl;
        return mat[x][y] + min (recurmincost(xD, yD, x+1, y+1),
                       recurmincost(xD, yD, x+1, y),
                       recurmincost(xD, yD, x, y+1) );
    }


}

int main()
{
    cout << recurmincost(2, 2, 0, 0) << endl;
    //cout << INT_MIN;
    //cout << minCost(2, 2);
    return 0;
}
