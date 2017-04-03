#include <stdio.h>
#include <iostream>

using namespace std;

int row, col;
int matrix[100][100];
void printmat();

bool isvalid(int x, int y)
{
    if(x >=0 && x < row && y >= 0 && y < col)
        return true;
    return false;
}

void bringdownH(int r, int p, int q)
{
    for(int i=r;i<row;i++)
    {
        if(matrix[i][p] == 0 && matrix[i][q] == 0)
        {
            matrix[i][p] = 1;
            matrix[i][q] = 1;

            matrix[i-1][p] = 0;
            matrix[i-1][q] = 0;
        }
    }

}

void bringdownV(int c, int p, int q)
{
    //cout << p+2 << " ### " << c << endl;
    for(int i=p+2;i<row;i++)
    {

        if(matrix[i][c] == 0)
        {
            //cout << "changing\n";
            matrix[i][c] = 1;
            matrix[i-2][c] = 0;
        }
    }
}

int boo()
{
    for(int i=row-2;i>=0;i--)
    {
        for(int j=0;j<col;j++)
        {



            if(matrix[i][j] == 1 && matrix[i-1][j] == 1)        // errorrrr
            {
                //cout << "vertical\n";
                bringdownV(j, i-1, i);
                //printmat();

            }
            else if(matrix[i][j] == 1 && matrix[i][j+1] == 1)
            {
                //cout << "horizontal\n";
                bringdownH(i, j, j+1);
                //printmat();
            }
        }
    }

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

int main()
{
    freopen("input1.txt", "r+", stdin);
    cin >> row >> col;
    cout << row << " * " << col << endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin >> matrix[i][j];
        }
    }
    printmat();
    boo();
    printmat();


    return 0;
}
