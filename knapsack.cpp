#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

//int wt[] = {10, 20, 30};
//int val[] = {60, 100, 120};

int wt[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int val[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int max(int a, int b)
{
    return (a > b)? a : b;
}

int knapsack(int W, int n)
{
    cout << n << " " << W << endl;

    if(W == 0 && n == 0)
    {
        //cout << W << " ";
        cout << "pial" << endl;
        return 0;

    }

    if(W == 0 || n == 0)
    {
        //cout << W << " ";

        return 0;
    }

    if(wt[n-1] > W)
        return knapsack(W, n-1);
    else
        return max(val[n-1] + knapsack(W - wt[n-1], n-1), knapsack(W, n-1));    // need to modify here

}

void gensubset(int num[], int size)
{
    int loop = pow(2, size);

    for(int i = 0; i < loop; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(i & (1 << j))
            {
                cout << num[j];
            }
        }
        cout << endl;
    }

}


int main()
{
    //cout << val[0] << endl;
    int W = 1;
    int n = sizeof(val)/sizeof(val[0]);


    //cout << knapsack(W, 10);
    int j = 4;
    //cout << (4<<2);

    //cout << ( 8 & 6);
    gensubset(val, 10);
    return 0;
}
