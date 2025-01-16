//selection sort
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
        printf("| %d |",arr[i]);      
    }printf("\n");
   for(i=0;i<n;i++)
   {
    int min=i;
    for(j=i+1;j<n;j++)
    {
        if(arr[min]>arr[j])
        {
            min=j;
        }
    }
    if(min!=i)
    {
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
   }
    printf("__after sorting__");
    printf("\n");
     for(i=0;i<n;i++)
    {
        printf("| %d |",arr[i]);      
    }printf("\n");
}