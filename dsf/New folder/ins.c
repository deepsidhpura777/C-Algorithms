#include<stdio.h>
//#include<conio.h>
void main()
{
int a[50],i,j,n,key,c;
printf("Enter the nos you wanna sort:");
scanf("%d",&n);
printf("Enter the respective nos:");
for(i=1;i<=n;i++)
{
scanf("%d",&a[i]);
}
for(j=2;j<=n;j++)
{
key=a[j];
c=j-1;
while(c>0 && a[c]>key)
{
a[c+1]=a[c];
c--;
}
a[c+1]=key;
}
printf("Sorted elements:\n");
for(j=1;j<=n;j++)
{
printf("%d\n",a[j]);
}




//getch();
}