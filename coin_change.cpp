#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;


int* way;

int coinchange2(int* coin, int sum, int k)
{

    way = new int[sum + 1];
    way[0] = 1;


    for(int j = 0; j < k; j++)
    {
        for(int i = sum; i >= 1; i--)
        {
            if(i >= coin[j] )
            {


                way[i] += way[i - coin[j]];
                cout << "hati\n";



            }
        }

    }
    return way[sum];
}

int len;

void print(int amount_left, int current_coin, int* coins)
{
    if(amount_left == 0)
    {
        cout << endl;
        return;
    }
    if(current_coin == len)
        return;
    if(way[amount_left - coins[current_coin]] > 0)
    {
        cout << coins[current_coin] << " ";
        print(amount_left - coins[current_coin], current_coin, coins);

    }
    print(amount_left, current_coin + 1, coins);

}


/*print_combinations(amount_left, current_coin):
    if amount_left == 0:
        print "\n"
        return
    if current_coin == num_coins:
        return
    if dp[amount_left - coins[current_coin]] > 0:
        print coins[current_coin], " "
        print_combinations(amount_left - coins[current_coin], current_coin)
    print_combinations(amount_left, current_coin + 1)

*/

int main()
{
    int i, j;
    int arr[] = {1, 2, 3, 4};
    int m = sizeof(arr)/sizeof(arr[0]);
    //printf("%d ", count(arr, m, 4));
    int n = 2;
    len = m;     // highest number of coins that can be taken
    int sum = 5;
    cout << "len is " << len << endl;


    cout << coinchange2(arr, sum, m) <<endl;
    for(int i = 0; i <= sum; i++)
        cout << way[i] << " ";
    //print(sum, 0, arr);

    return 0;
}


/*
int coinchange1(int coin[], int k, int n) // a variant where we find out that if a number can be made out of the coins using each
{                                       // coins as many times as possible
    int possible[100];
    memset(possible, 0, sizeof(possible));
    possible[0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            if(i >= coin[j])
                possible[i] += possible[i - coin[j]];
        }
    }

    for(int i=0;i<=n;i++)
        cout << possible[i] << " ";
    cout << endl;
    return possible[n];
}
*/
