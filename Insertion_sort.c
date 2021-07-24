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
void insertion_sort(int a[],int n)
{
    int i,hole,value;
    for(i=1;i<n;i++)
    {
        value=a[i];
        hole=i;
        while(hole>0 && a[hole-1]>value)
        {
            a[hole]=a[hole-1];
            hole--;
        }
        a[hole]=value;
        printf("After checking value at %d :\n",i);
        display(a,n);
    }
}
void main()
{
    int a[10],i,n;
    printf("Enter no of elements in array\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Unsorted array\n");
    display(a,n);
    insertion_sort(a,n);
    printf("Sorted array\n");
    display(a,n);
}