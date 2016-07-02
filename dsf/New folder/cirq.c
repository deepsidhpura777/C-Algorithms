#include<stdio.h>
//#include<conio.h>
#define size 6
int array[6],front=-1,rear=-1;
void insert(int n)
{
	if(front==-1 && rear==-1)
	{front++;rear++;}
	if((rear+1)%size==front)
	{       printf("Queue Full...\n");


	}
	else
	{
		array[rear]=n;
		rear=(rear+1)%size;

	}
}
int del()
{
	if(front!=rear)
	{
	int delno=array[front];
	front=(front+1)%size;
	printf("The deleted element is:%d\n",delno);
	return delno;
	}
	else
	{
	printf("Queue Empty...\n");
	return 0;
	}
}



void main()
{
int input[5];
int i,j,choice,n;
//clrscr();
printf("Choose the operations:\n1.Insert\n2.Delete\n3.Exit(Press 0)\n");
scanf("%d",&choice);

while(choice!=0)
{
switch(choice)
{
case 1:printf("Enter the element to Insert:\n");
       scanf("%d",&n);
       insert(n);
break;
case 2:del();
break;
default:printf("Invalid Choice\n");
break;

}
printf("Enter your choice:\n");
scanf("%d",&choice);
}
//getch();
}