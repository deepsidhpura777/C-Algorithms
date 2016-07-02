#include<stdio.h>
//#include<conio.h>

int arr[6],dig[6],buck[10][6]={0,0},counter[10]={0},max=0,maxdigit=0,N,n=1;

void extract(int j)
{
int i;
switch(j)
{
case 1:		for(i=1;i<=N;i++)
			{
				dig[i]=arr[i]%(10);
						
			}
break;
case 2:		for(i=1;i<=N;i++)
			{
				dig[i]=arr[i]/(10);
						
			}
break;
case 3:		for(i=1;i<=N;i++)
			{
				dig[i]=arr[i]/(100);
						
			}
break;
}
}

void main()
{
int i,j,k,m,digit,number;
//clrscr();
printf("Enter no of elements to be sorted:");
scanf("%d",&N);
printf("Enter the respective elements:");
for(i=1;i<=N;i++)
{
scanf("%d",&arr[i]);
}
for(i=1;i<=N;i++)
{
if(arr[i]>max)
max=arr[i];
}
//printf("Max:%d\n",max);
while(max!=0)
{
max=max/10;
maxdigit++;
}
//printf("Maxdigit:%d\n",maxdigit);
for(m=1;m<=maxdigit;m++)
{
extract(m);

for(k=1;k<=N;k++)
{
 digit=dig[k];
 number=arr[k];
switch(digit)
{
case 0:buck[0][counter[0]++]=number;
break;
case 1:buck[1][counter[1]++]=number;
break;
case 2:buck[2][counter[2]++]=number;
break;
case 3:buck[3][counter[3]++]=number;
break;
case 4:buck[4][counter[4]++]=number;
break;
case 5:buck[5][counter[5]++]=number;
break;
case 6:buck[6][counter[6]++]=number;
break;
case 7:buck[7][counter[7]++]=number;
break;
case 8:buck[8][counter[8]++]=number;
break;
case 9:buck[9][counter[9]++]=number;
break;
}
}
for(i=0;i<=9;i++)
{
for(j=0;j<=9;j++)
{
if(buck[i][j]!=0)
{
arr[n]=buck[i][j];
n++;
buck[i][j]=0;
}
}
}
n=1;
for(i=0;i<=9;i++)
counter[i]=0;
}
for(i=1;i<=N;i++)
{
printf("%d\n",arr[i]);
}





//getch();
}