#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

int c;

void fun(int *p)
{
  int q = 10;
  p = &q;
  cout << "content of p in fun " << *p << endl;
}

int compare(int a, int b)
{
    if(a > b )
        return -1;
    else
        return 1;
}

void bubblesort(int* arr, int size, int(*comp)(int, int) )
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size-1; j++)
        {
            if(comp(arr[j], arr[j+1]) > 0)
                swap(arr[j], arr[j+1]);
        }
    }
}

int *add(int* a, int* b)
{

    c = (*a) + (*b);

    cout << c << " " << &c <<  endl;
    return &c;

}

int boo(int a, int b)
{
    return a + b;
}

void A(int (*hati)(int, int))
{
    cout << "hello world\n";
    cout << hati(100, 200);


}


int main()
{
    int a = 5;
    int b = 6;
    int* c = add(&a, &b);
    printf("%d\n", *c);
    //cout << *c << endl;

    int (*funVar)(int, int);
    funVar = &boo;
    cout << funVar(2, 3) << endl;

    cout << "size of function " << sizeof(funVar);
    A(&boo); // also same A(funVar) and A(boo) ;

    cout << endl << endl;
    int arr[] = {42,5,6,1,3,64,32,0,123};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, len, compare);
    for(int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;


    /*char p[] = "PIAL";

    cout << sizeof(p) << " " << strlen(p) << endl;
    printf("%s\n", p);

    char* p1 = p;
    //p1++;
    cout << *(p1+2) << endl;
    */


    int r =  65536;
    int* p = &r;
    fun(p);
    printf("%d", *p);

    int *x;
    x = &r;
    char* ppp = (char*)x;
    cout << (*ppp + 2);
    return 0;

}
