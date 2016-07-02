#include<stdio.h>

int n;int a[25];
void main()
{

printf("Enter the no of elements:\n");
scanf("%d",&n);
printf("Enter the elements:");
for(int i=1;i<=n;i++)
{
scanf("%d",&a[i]);
}
quicksort(1,n);
printf("The sorted elements are:");
for(int i=1;i<=n;i++)
{
printf("%d\n",a[i]);
}
}

void swap(int i,int j)
{
int temp=i;
i=j;
j=temp;
}

int partition(int p,int r)
{
int j;
int i=p-1;
int pivot=a[r];
for(j=p;j<r;j++)
{
   if(a[j]<pivot)
   {
      i++;
      swap(a[i],a[j]);
   }

}
i++;
swap(a[i],pivot);
return i;
}

void quicksort(int p,int r)
{

q=partition(p,r);
quicksort(p,q);
quicksort(q+1,r);
}




