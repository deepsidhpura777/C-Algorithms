#include<stdio.h>
#define MAX 10

void table(int a[MAX],int n,int key)
{

int i=0,c=0,flag=0;
if(a[key]==-1)
a[key]=n;

else
{
	while(i<MAX)
	{
		if(a[i] != -1)
		c++;
		i++;
	}
	if(c==MAX)
		printf("Hash table is Full\n");

	for(i=key+1;i<MAX;i++)
	{
		if(a[i]==-1)
		{
			a[i]=n;
			flag=1;
			break;
		}		
	}
	
	for(i=0;i<key&&flag==0;i++)
	{
		if(a[i]==-1)
		a[i]=n;
		flag=1;
		break;
	}


}
}

void display(int a[MAX])
{
int i;
for(i=0;i<MAX;i++)
printf("\n%d %d\n",i,a[i]);
}


void main()
{
int a[MAX];
int n,i;
char ch;
for(i=0;i<MAX;i++)
{
a[i]=-1;
}
do
{
printf("\nEnter the no:\n");
scanf("%d",&n);
int key=n%10;
table(a,n,key);
printf("Do you wish to continue:\n");
ch=getche();
}
while(ch!='n');
display(a);
}