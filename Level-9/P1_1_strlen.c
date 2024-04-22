// 1. strlen - calculate the length of a string

#include<stdio.h>
#include<string.h>
#define size 20 

int main() 
{
    char str[size];
    printf("Enter the string : ");
    scanf("%s",str);
    int len = strlen(str);
    printf("The length string is : %d\n",len);
    return 0;
}
