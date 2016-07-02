#include<stdio.h>                                                         								/* Deep Sidhpura
																			 SE Comps Roll 71.
																			 Batch=D*/
void mergesort(int,int);
void merge(int,int,int);
int n;
int a[25],k;
void main()
{

printf("Enter the no of elements:\n");
scanf("%d",&n);
printf("Enter the elements:");
for(k=1;k<=n;k++)
{
scanf("%d",&a[k]);
}
mergesort(1,n);
printf("The sorted elements are:\n");
for(k=1;k<=n;k++)
{
printf("%d\n",a[k]);
}
}

void merge(int p,int q,int r)
{
  int n1,n2,i,j,l,L[25],R[25];
 n1=q-p+1;
 n2=r-q;
 
 for(i=1;i<=n1;i++)
 {
	L[i]=a[p+i-1];
	
 }
 for(j=1;j<=n2;j++)
 {
	R[j]=a[q+j];
	
 }
 
 L[n1+1]=1000;
 R[n2+1]=1000;
 i=1;
 j=1;
 
 for(l=p;l<=r;l++)
 {
	if(L[i]<=R[j])
	{
	a[l]=L[i];
	i++;
	}
	else
	{
		a[l]=R[j];
		j++;
	}
 }
for(k=1;k<=n;k++)
{
printf("%d\t",a[k]);
}  
printf("\n");  
 
}

void mergesort(int p,int r)
{    
    int q;
    if(p<r)
	{
		q=(p+r)/2;
		mergesort(p,q);
		mergesort(q+1,r);
		merge(p,q,r);
	}
}





