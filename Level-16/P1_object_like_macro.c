// 1. Object-like Macros

#include<stdio.h>
#define PI 3.143
int main()
{
    float r, area;
    printf("Enter the radius:");
    scanf("%f",&r);
    area = PI*r*r;
    printf("Area of circle : %f\n",area);
    return 0;
}
