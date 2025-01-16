#include <stdio.h>
int main()
{
    int i,j,n;
    int arr[20];
    printf("enter the number of elements");
    printf("\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the element");
        printf("\n");
        scanf("%d",&arr[i]);
    }
     printf("__before sorting__");
     printf("\n");
     for(i=0;i<n;i++)
    {
        printf("|\t%d\t|",arr[i]);      
    }printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("__after sorting__");
    printf("\n");
     for(i=0;i<n;i++)
    {
        printf("|%d\t|",arr[i]);      
    }printf("\n");
}