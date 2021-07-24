#include<stdio.h>


void sort(int a[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
                {
                    int temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
        }
    }
}

int binary_search(int a[],int first,int last,int key)
{
    if(last>=first)
    {
    int mid=(first+last)/2;
    if(key==a[mid])
        return mid;
    if(key<a[mid])
       return (binary_search(a,first,mid-1,key));
    else
       return (binary_search(a,mid+1,last,key));
    }
    return -1;
}
void main()
{
    int n,a[10],i,search,f,l;
    printf("enter no of elements\n");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
   
    sort(a,n);
    printf("sorted array\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nenter search element\n");
    scanf("%d",&search);
    f=0;
    l=n-1;
   int index=binary_search(a,f,l,search);
   if(index==-1)
   {
       printf("Number not found\n");

   }
   else
   {
       printf("Number found at index=%d\n",index);
   }
}