// 1. strlen - calculate the length of a string

#include <stdio.h>

int stringLength(char* str) 
{
    if (*str == '\0') 
    {
        return 0;
    } 
    else 
    {
        return 1 + stringLength(str + 1);
    }
}


int main() 
{
    char str[100];
    printf("Enter the string:\n");
    scanf("%s", str);
    int length = stringLength(str);
    printf("Length of the string: %d\n", length);
    return 0;
}

