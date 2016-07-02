#include<stdio.h>
#define MAX 10

int a[MAX];
int top=-1;

void push(int n)
{
a[++top]=n;
}

int pop()
{
int d = a[top--];
return d;
}

void dec(int n)
{
int temp=n;
	while(temp>=1)
	{
		int r=temp%2;
		push(r);
		temp=temp/2;
	}

	while(top>=0)
	{
		printf("%d",pop());
	
	}

}

void main()
{
int n;
printf("Enter the number:");
scanf("%d",&n);
printf("The Binary Number is:\n");
dec(n);
}