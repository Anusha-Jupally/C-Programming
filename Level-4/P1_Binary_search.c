/* Implement binary searching algorithm */

#include <stdio.h>
#define size 20
int binary_search(int arr[],int left,int right,int key)
{
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            left=mid+1;
        else
            right=mid-1;
    }
    return -1;
}
int main()
{
    int arr[size],key,n,i;
    printf("Enter no of elements:");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the element to search:");
    scanf("%d",&key);
    
    int index=binary_search(arr,0,n-1,key);
    
    if(index==-1)
        printf("Key not found\n");
    else
        printf("%d found at index %d\n",key,index);
}
