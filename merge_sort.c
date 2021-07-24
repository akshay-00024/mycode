#include<stdio.h>

void merge(int a[],int low,int mid,int high)
{ int i,j,b[30],k=0;
    i=low;
    j=mid+1;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        b[k++]=a[i++];
    }
    while(j<=high)
    {
        b[k++]=a[j++];
    }
    k=0;
    for(i=low;i<=high;i++)
    {
        a[i]=b[k];
        k++;
    }
}

void merge_sort(int a[],int low,int high)
{
    
    int mid;
    if(low<high)
    {
    mid=(low+high)/2;
    merge_sort(a,low,mid);
    merge_sort(a,mid+1,high);
    merge(a,low,mid,high);
    }
}
void display(int a[],int n)
{
    int i;
    printf("[");
    for(i=0;i<n;i++)
    {
        printf("%d, ",a[i]);
    }
    printf("]\n");
}
void main()
{
    int a[30],n,i;
    printf("Enter how many elements\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Unsorted elements are:\n");
    display(a,n);
    merge_sort(a,0,n-1);
    printf("Sorted elements are:\n");
    display(a,n);
}