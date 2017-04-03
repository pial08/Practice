#include <stdio.h>
#include <iostream>

using namespace std;

int letter[3][3] = {{1,0,1},
                  {1,1,1},
                  {1,0,1},
                    };

int matrix[100][100];
int row, col;

int findLetter(int x, int y)
{
    //cout << x << " ** " << y << endl;
    if(x+3 > row || y+3 > col)
        return 0;

    for(int i=x,p=0;i<3+x;i++,p++)
    {
        for(int j=y,q=0;j<3+y;j++,q++)
        {
            //cout << matrix[i][j] << " ";
            if(matrix[i][j] != letter[p][q])
            {

                return 0;

            }
            //cout << matrix[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << endl ;
    return 1;

}

int main()
{
    freopen("input.txt", "r+", stdin);

    cin >> row >> col;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int val;
            cin >> val;
            matrix[i][j] = val;
            //cout << matrix[i][j] << " ";
        }
        //cout << endl;
    }

    int counter = 0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            counter += findLetter(i,j);
        }
    }
    cout << counter << endl;

    return 0;
}
