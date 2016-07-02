#include<stdio.h>
//#include<conio.h>
void main()
{
int i,j,d,key,a[10],n,c,temp;
//clrscr();
printf("Enter the no of elements you wanna shell sort:");
scanf("%d",&n);
printf("Enter the respective elements:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=n/2;i>=1;i=i/2)
{
	for(j=i;j<=n;j++)
	{
		key=a[j];
		c=j-i;
			while(c>=0 && a[c]>key)
			{
			 a[c+i]=a[c];
			 c=c-i;
			}
		a[c+i]=key;
	}

}
for(i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
//getch();
}
