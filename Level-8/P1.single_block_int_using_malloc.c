// 1.Program to allocate a single block of integer using malloc

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    ptr=(int*)malloc(sizeof(int));
    if(ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    scanf("%d",ptr);
    printf("%d\n",*ptr);
    free(ptr);
}
