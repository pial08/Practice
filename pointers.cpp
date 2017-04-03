#include <stdio.h>
#include <iostream>

using namespace std;

int findNoOfOccurence(int arr[], int left, int right, int val, int flag)
{
    int result = -1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(arr[mid] == val)
        {
            result = mid;
            if(flag)
            {

                right = mid - 1;
            }
            else
            {

                left = mid + 1;
            }
        }
        else if(val < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;

    }
    return result;
}


int sum(int* A)
{
    int sum = 0;
    int s = sizeof(A)/sizeof(A[0]);
    s = 5;

    for(int i = 0; i < s; i++)
    {
        cout << A[i] << " ";
        sum += A[i];
    }
    return sum;
}

int *add(int* a, int* b)
{
    int c;
    c = (*a) + (*b);
    cout << c;
    return &c;
}

void printHello()
{
    cout << "Hellow World\n";
}

int main()
{
    int a = 5;
    int *b;
    b = &a;
    cout << *b << endl;

    cout << "address of a is " << &a << endl;

    printf("Address of a is %d\n", &a);

    int arr[] = {1, 2, 3, 4, 5, 5, 5, 5, 8, 8, 8};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << endl << endl;

    cout << arr << endl;
    cout << &arr[0] << endl;
    cout << *(arr + 0) << endl;
    cout << &arr[1] << endl;

    cout << endl << endl;
    //cout << sum(arr);

    int x = findNoOfOccurence(arr, 0, len - 1, 5, true);
    int y = findNoOfOccurence(arr, 0, len - 1, 5, false);
    cout <<  y << " " << x << " " << y - x + 1 << endl;


    void *ptr;
    //int a = 5;
    ptr = &a;
    cout << *(int*)ptr << endl;

    cout << NULL << endl;
    printf("%d\n", sizeof(void*));

    //****** pointers as function returns************//

    int aa = 5, bb = 6;
    int* pial = add(&aa, &bb);

    printHello();

    cout << *pial << endl;


    return 0;
}
