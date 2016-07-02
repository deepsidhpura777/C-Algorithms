#include<stdio.h>

static int c;
int fact(int n)
{
int p=1;
int i;
	for(i=1;i<=n;i++)
		{
			p=p*i;
		}
return p;
}

int combination(int n,int m)
{
int factn=fact(n);
int factm=fact(m);
int factd=fact(n-m);
int comb=factn/(factm*factd);
return comb;
}

void pascal(int n,int r)
{


int i,m=0;
	if(n<=r)
	{
		for(i=1;i<=c;i++)
			{
				printf(" ");
			}
		for(i=r;i>=c;i--)
			{
				printf("%d",combination(n,m));
				printf(" ");
				m++;
			}
		c--;
		printf("\n");
		pascal(n+1,r);
	}
}

void main()
{
int r;

printf("Enter the no of rows:");
scanf("%d",&r);
c=r;
pascal(0,r);
}