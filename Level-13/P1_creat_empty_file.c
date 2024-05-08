// 1.Program to create an empty file

#include<stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("file1.txt","r");
    if(fp == NULL)
    {
        printf("Error in opening file\n");
    }
    else
    {
        printf("File opened successfully\n");
    }
    fclose(fp);
    return 0;
}
