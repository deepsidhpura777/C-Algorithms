#include<stdio.h>
#define MAX 10


void ind()
{
int a[MAX],index[MAX/5];
int i,n;
int low=0,high=10,flag=0;
//index[0]=0;
printf("Enter the 10 elements:\n");
	for(i=0;i<MAX;i++)
	{
		scanf("%d",&a[i]);
		if(i%5==0)
		index[i/5]=i;
	}
printf("Enter the element to search:\n");
scanf("%d",&n);
	for(i=1;i<MAX/5;i++)
	{
		if(n<a[index[i]])
		{
			low=index[i-1];
			high=index[i+1];
			break; //Beacuse we want the first occurence
		}
	}
printf("Low:%d\n",low);
printf("High:%d\n",high);
printf("Index 0:%d\n",index[0]);
printf("Index 1:%d\n",index[1]);	
	for(i=low;i<=high;i++)
	{
		if(a[i]==n)
		{
			printf("Element found at position:%d\n",i+1);
			flag=1;
			break;
		}
	}
	if(flag==0)
	printf("Element not found");
}

void inter(int low,int high,int arr[MAX],int key)
{
int middle,j;
middle=low+(high-low)*((key - arr[low]) / (arr[high]-arr[low]));


if(key == arr[middle])
{
printf("Element found at position:%d\n", middle+1);
}
else
{
	if(key < arr[middle])
	{
	
	inter(low,(middle-1),arr,key);
	}
	else
	{
	inter((middle+1),high,arr,key);
	}

}
}

void main()
{
int c;
int n;
int j;
int b[10];
printf("1.Index sequential Search\n2.Interpolation Search\n");
scanf("%d",&c);
while(c!=0)
{
switch(c)
{
case 1:ind();
break;
case 2:printf("Enter the 10 elements:\n");
	for(j=0;j<MAX;j++)
	{
		scanf("%d",&b[j]);
	}

printf("Enter the element to search:\n");
scanf("%d",&n);
inter(0,9,b,n);
break;

}
printf("Select your choice:\n");
scanf("%d",&c);
}

}