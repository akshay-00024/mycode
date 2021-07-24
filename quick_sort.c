#include<stdio.h>


void display(int a[],int n)
{
    printf("[");
    for(int i=0;i<n;i++)
    {
        printf("%d ,",a[i]);
    }
    printf("]\n");
}

void quick_sort(int a[],int L,int H)
{

     if(L>=H)
     return;
    int pivot,low,high,temp;
    pivot=a[L];
    low=L+1;
    high=H;
   
    while(low<=high)
    {
        while(low<=high && a[low]<pivot)
        {
            low++;
        }
        while(a[high]>pivot)
        {
            high--;
        }
        if(low<=high)
        {
            temp=a[low];
            a[low]=a[high];
            a[high]=temp;
            low++;
            high--;
        }
    }
    temp=a[L];
    a[L]=a[high];
    a[high]=temp;
   // if(L<high-1)
    quick_sort(a,L,high-1);
    
   // if(H>low)
    quick_sort(a,high+1,H);
}
void main()
{   int a[20],n,i;
    printf("Enter the no of elements\n");
    scanf("%d",&n);
    printf("Enter array elements\n");
   for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    printf("Unsorted elements are:\n");
    display(a,n);
    quick_sort(a,0,n-1);
    printf("Soretd elements are:\n");
    display(a,n);
}