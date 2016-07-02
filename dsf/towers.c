#include<stdio.h>

void towers(int n,char from,char to,char aux)
{
	if(n==1)
	{
		printf("Move the disk 1 from %c to %c \n",from,to);
		return;
	}
	towers(n-1,from,aux,to);
	printf("Move the disk %d from %c to %c \n",n,from,to);
	towers(n-1,aux,to,from);
}

void main()
{
int n;
printf("Enter the no of disks:\n");
scanf("%d",&n);
printf("The solution is:\n");
towers(n,'A','C','B');
}