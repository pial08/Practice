#include<stdio.h>
#include<iostream>
#include<limits.h>

using namespace std;

int multiply(int p[], int i, int j)
{
	if(i==j)
		return 0;
	int min = INT_MAX;
	int k;
	int count;
	
	for(k=i;k<j;k++)
	{
		count = multiply(p,i,k) + multiply(p,k+1,j) + p[i-1]*p[k]*p[j];
		
		if(count < min) 
		{
			min = count;
		}
	}
	return min;
	
}

int main()
{
	int arr[] = {1,2,3,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << multiply(arr,1,n-1) << endl;
	return 0;

}
