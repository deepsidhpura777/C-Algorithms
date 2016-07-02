#include<stdio.h>                                                         						   /* Deep Sidhpura
																			 SE Comps Roll No 71.
																			 Batch=D*/
void quicksort(int,int);
int partition(int,int);
int n;
int a[25],k,q;
void main()
{

printf("Enter the no of elements:\n");
scanf("%d",&n);
printf("Enter the elements:");
for(k=1;k<=n;k++)
{
scanf("%d",&a[k]);
}
quicksort(1,n);
printf("The sorted elements are:\n");
for(k=1;k<=n;k++)
{
printf("%d\n",a[k]);
}
}



int partition(int p,int r)
{
static int j;
static int i;
i=p-1;
static int pivot;
pivot=a[r];
static int temp,temp1;
for(j=p;j<r;j++)
{
   if(a[j]<pivot)
   {
      i++;
	  temp=a[i];
	  a[i]=a[j];
      a[j]=temp;
      
   }

}
i++;
temp1=a[i];
a[i]=a[r];
a[r]=temp1;

for(k=1;k<=n;k++)
{
printf("%d\t",a[k]);
}  
printf("\n");   

return i;
}

void quicksort(int p,int r)
{
if(p<r)
{
q=partition(p,r);
quicksort(p,q-1);
quicksort(q+1,r);
}
}




