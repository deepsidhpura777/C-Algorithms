#include<stdio.h>

static int orgkey;


void quadprob(int a[10],int key,int num,int i)
{
	if(a[key]==-1)
	a[key]=num;
	
	else
	{
		key=(orgkey+i*i)%10;
		quadprob(a,key,num,i+1);
	}
	
}

void display(int a[10])
{
int i;
printf("The Hash table is:\n");
for(i=0;i<10;i++)
printf("%d %d\n",i,a[i]);
}






void main()
{
int n,i;
int choice;
int a[10];
for(i=0;i<10;i++)
{
a[i]=-1;
}
printf("Press 1 to enter elements and zero to stop:");
scanf("%d",&choice);
while(choice!=0)
{
printf("Enter the element:");
scanf("%d",&n);
orgkey=n%10;
quadprob(a,orgkey,n,0);
printf("Enter your choice:");
scanf("%d",&choice);
}

display(a);

}