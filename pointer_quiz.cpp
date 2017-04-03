#include<stdio.h>
#include <iostream>

using namespace std;
void f(int *p, int *q)
{
  p = q;
  *p = 2;
  printf("%d %d\n", *p, *q);
}
int i = 0, j = 1;
int main()
{
  f(&i, &j);
  printf("%d %d \n", i, j);


  int arr[] = {1,2,3};
  cout << 0[arr] << endl;
  return 0;
}
