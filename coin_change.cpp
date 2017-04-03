#include <stdio.h>
#include <iostream>

using namespace std;

int coinChange(int coin[], int n, int m)	// n mumber of coins
{
	if(m==0)
		return 1;
	if(m<0) 
		return 0;
		
	if(n<=0 && m>0)
		return 0;
	
	return coinChange(coin, n, m-coin[n-1]) + coinChange(coin,n-1,m);
}
int main()
{
	int coin[] = {1,2,3};
	int n = sizeof(coin)/sizeof(coin[0]);
	cout << coinChange(coin,n,4) << endl;

    return 0;
}
