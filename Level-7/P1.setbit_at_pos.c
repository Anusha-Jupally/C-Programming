/* 1.Program to set a bit at a particular position in an integer */

#include<stdio.h>
int main()
{
    int num,setbit,pos;
    printf("Enter the number:\n");
    scanf("%d",&num);
    printf("Enter the postion to set a bit:\n");
    scanf("%d",&pos);
    setbit=num | (1<<pos);
    printf("NUmber after setting %d bit is %d\n",pos,setbit);
}
