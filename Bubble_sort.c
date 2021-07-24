#include<stdio.h>

void display(int arr[],int n)
{
    int i;
    printf("[");
    for(i=0;i<n;i++)
    {
        printf("%d,",arr[i]);
    }
    printf("]\n");
}

void swap(int *a,int *b)
{
    int temp=*a;
        *a=*b;
        *b=temp;
}
void bubble_sort(int arr[],int n)
{
    int i,itr,flag=0;
    for(itr=1;itr<n;itr++)
    {
        printf("Iteration %d:\n",itr);
        for(i=0;i<n-itr;i++)
        {
            printf("Compared elements:[%d,%d]\n",arr[i],arr[i+1]);
            if(arr[i]>arr[i+1])
            {
                flag=1;
                printf("Swapped elements:[%d,%d]\n",arr[i],arr[i+1]);
                swap(&arr[i],&arr[i+1]);
            }

        }
        
        display(arr,n);
        if(flag==0)
        break;
    }
}
void main()
{
    int arr[10],i,n;
    printf("Enter the no of elements\n");
    scanf("%d",&n);
    printf("Enter Array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Unsorted Array is:\n");
    display(arr,n);
    bubble_sort(arr,n);
    printf("Sorted array is:\n");
    display(arr,n);
}