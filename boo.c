#include <stdio.h>
#include <stdlib.h>
int c;

int *add(int* a, int* b)
{
    c = (*a) + (*b);
    printf("%d\n", &c);

    return &c;

}

int main()
{
    int a = 2;
    int b = 4;
    int* ptr = add(&a, &b);
    printf("%d\n", ptr);
    printf("%d", *ptr);

    return 0;

}

