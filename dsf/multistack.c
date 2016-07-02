#include<stdio.h>
//#include<conio.h>
int stack[100],base[10],top[10];

void push()
{
int n,sindex,input;
printf("Enter the stackno in which you wanna push:");
scanf("%d",&n);

if(top[n]<base[n+1])
{
printf("Enter ele to be pushed:");
scanf("%d",&input);
stack[top[n]++]=input;

}
else
{
printf("Stack full....\n");
}
}
void pop()
{
int n,ele;
printf("Enter the stack no from which you wanna pop:");
scanf("%d",&n);
if(top[n]>base[n])
{
ele=stack[top[n]-1];
printf("%d\n",ele);
top[n]--;
}
else
printf("Stack empty....\n");
}



void main()
{
int stackno,userinput,i,j,k;

printf("Enter No of Stacks to maintain:");
scanf("%d",&stackno);
for(i=1;i<=stackno;i++)
{
base[i]=1+(i-1)*(100/stackno);
top[i]=base[i];
}
base[stackno+1]=100;


printf("Choose the following option:\n");
printf("1.Push\n");
printf("2.Pop\n");
//printf("3.Display\n");
printf("Press 0 for exiting\n");
scanf("%d",&userinput);
while(userinput!=0)
{
switch(userinput)
{
case 1:push();
       break;
case 2:pop();
       break;
default:printf("Wrong Choice");
}
//clrscr();
printf("Choose the following option:\n");
printf("1.Push\n");
printf("2.Pop\n");
//printf("3.Display");
printf("Press 0 for exiting\n");
printf("Enter new choice\n");
scanf("%d",&userinput);
}

//getch();
}