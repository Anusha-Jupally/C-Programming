// 1. Implement strlen - calculate the length of a string

#include<stdio.h>
int stringlength(char* str);
int main()
{
    char str[100];
    printf("Enter the string:\n");
    scanf("%s",str);
    int length=stringlength(str);
    printf("Length of the string : %d\n",length);
    return 0;
}
int stringlength(char* str)
{
    int length=0;
    while(str[length] != '\0')
    {
        length++;
    }
    return length;
}
