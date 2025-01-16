#include <stdio.h>
int merge(int arr[], int l, int m,int h) {
    int  n1=m-l+1;
    int n2=h-m;
    int la[n1],ra[n2];
    for(int i=0;i<n1;i++)
    {
        la[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        ra[j]=arr[m+1+j];
    }
    int i=0,j=0,k=l;
    while(i<n1&&j<n2)
    {
        if(la[i]<ra[j])
        {
            arr[k]=la[i];
            i++;
        }
        else{
            arr[k]=ra[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=la[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=ra[j];
        j++;
        k++;
    }
}
void print(int arr[],int n)
{
    int i;
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void mergesort(int arr[], int l, int h) {
    if (l < h) 
    {
        int m = (l+h)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1,h);
        merge(arr,l,m,h);
    }
}

int main() {
    int n;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
     print(arr,n);

    mergesort(arr,0,n-1);
    printf("sorted array");
    print(arr,n);
    

    return 0;
}