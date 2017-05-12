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

        return mat[x][y] + min (recurmincost(xD, yD, x+1, y+1),
                       recurmincost(xD, yD, x+1, y),
                       recurmincost(xD, yD, x, y+1) );
    }


}

void print(int arr[3][3], int m, int n)
{

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int min_pathDp(int m, int n)
{
    int dp[3][3];
    // copy the array
    dp[0][0] = mat[0][0];
    for(int i = 1; i <= m; i++)
    {
        dp[i][0] = mat[i][0] + dp[i-1][0];
        //cout << dp[i][0] << " ";
    }
    cout << endl;
    for(int i = 1; i <= n; i++)
    {
        dp[0][i] = mat[0][i] + dp[0][i-1];
    }

    print(dp, m, m);



    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + mat[i][j];
        }
    }

    print(dp, m, m);


}

int main()
{
    //cout << recurmincost(2, 2, 0, 0) << endl;
    cout << "Main matrix " << endl;
    print(mat, 2,2);
    min_pathDp(2, 2);

    /*for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << endl;

    //cout << INT_MIN;
    //cout << minCost(2, 2);
    return 0;
}
