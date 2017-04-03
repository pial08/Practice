#include <stdio.h>
#include <iostream>

using namespace std;

int arr[] = {1, 54, 88, 6, 55, 7};
int len = 5;

void printrevarray(int i)
{
    if(i > len/2)
        return;
    cout << arr[i] << " " << arr[len-i-1] << endl;
    printrevarray(i+1);

}
int newlen = 0;
void removeodd(int i, int j)
{
    if(i==len)
    {
        len = j;
        return;
    }

    if(arr[i] % 2 == 0)
    {
        arr[j++] = arr[i];
    }
    removeodd(i+1,j);



}

int main()
{
    //printrevarray(0);

    removeodd(0, 0);

    for(int i=0;i<len;i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
