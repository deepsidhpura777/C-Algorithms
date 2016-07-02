#include<stdio.h>
//#include<conio.h>
int front=-1,rear=-1;
int a[50];
void insertrear(int n)
{
if(front==-1&&rear==-1)
{
front++;
rear++;
}
a[rear]=n;
rear++;
}
int deletefront()
{
int del=a[front];
a[front]=7;
front++;
return del;
}
void insertfront(int n)
{
int j=rear;
while(j>=front)
{
a[j+1]=a[j];
j--;
}
a[front]=n;
rear++;
}
int deleterear()
{
int del=a[rear-1
];
a[rear]=7;
rear--;
return del;
}
void display()
{
int i;
for(i=0;i<rear;i++)
if(a[i]!=7)
{
printf("%d\n",a[i]);
}
}
void main()
{
int choice,n1,n2;
//clrscr();
printf("Select one of the following:\n1.Insert Rear\n2.Delete Front\n3.Insert Front\n4.Delete Rear\n5.Display\n");
scanf("%d",&choice);
while(choice!=0)
{
switch(choice)
{
case 1: printf("Enter the element to be inserted at the rear:\n");
	scanf("%d",&n1);
	insertrear(n1);
break;
case 2:printf("The deleted element from the front is:%d\n",deletefront());
break;
case 3: printf("Enter the element to be inserted at the front:\n");
	scanf("%d",&n2);
	insertfront(n2);
break;
case 4:printf("The deleted element from the rear is:%d\n",deleterear());
break;
case 5:display();
break;
}
printf("Enter your choice:\n");
scanf("%d",&choice);
}
//getch();
}