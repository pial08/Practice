#include <stdio.h>
#include <iostream>

using namespace std;
int num[1000];

void mergesort(int arr[], int low, int high)
{

    if(low == high)
        return ;
    int mid = (low + high)/2;
    mergesort(arr, low, mid);
    mergesort(arr, mid+1, high);

    int i,j,k;

    for(i=low, j=mid+1, k=low; k <= high; k++)
    {
        if(i == mid+1)
            num[k] = arr[j++];
        else if(j == high+1)
            num[k] = arr[i++];
        else if(arr[i] > arr[j])
            num[k] = arr[i++];
        else
            num[k] = arr[j++];
    }

    for(k = low; k <= high; k++)
    {
        arr[k] = num[k];
    }

}

int main()
{

    int arr[] = {54,12,42,0,1,6,23,89};
    int len = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr, 0, len-1);
    for(int i=0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << len << endl;
    return 0;
}
