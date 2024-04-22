// 1. fp is a function pointer which can hold the address of a function which takes two integers as a parameter and returns an integer

#include <stdio.h>

typedef int (*fptr)(int, int);
int sum(int a, int b);

int main() 
{
    int a, b;
    printf("Enter two numbers:\n");
    scanf("%d %d", &a, &b);
    fptr fp;
    fp = &sum;
    int result = (*fp)(a, b);
    printf("Sum of %d and %d is: %d\n", a, b, result);
    return 0;
}
int sum(int a, int b) 
{
    return a + b;
}
