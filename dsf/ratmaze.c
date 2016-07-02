#include<stdio.h>
int finaldes=0;

void findPath(int a[10][10],int x,int y,int sol[10][10],int N)
{
int dir1=0,dir2=0;
	if(x==N && y==N)
	{
	finaldes=1;
	}	
	else
	{
		if(x<=N || y<=N)
		{
			sol[x][y]=1;
			if(a[x+1][y]==1)
			{
				findPath(a,x+1,y,sol,N);
				dir1=1;
			}
			
			
			

			if(a[x][y+1]==1)
			{
				findPath(a,x,y+1,sol,N);
				dir2=1;
		
			}
			
			
			
			if(dir1==0 && dir2==0)
			{
			sol[x][y]=0;
			}
			//dir1=0;dir2=0;
		}
	    
		
	}
}

void main()
{
int i,j,a[10][10],solution[10][10]={0,0},N;
printf("Enter the dimensions of the maze for the problem:");
scanf("%d",&N);
printf("Enter the of the maze for the problem:\n");
for(i=1;i<=N;i++)
{
for(j=1;j<=N;j++)
scanf("%d",&a[i][j]);
}
findPath(a,1,1,solution,N);
printf("The solution is:\n");
for(i=1;i<=N;i++)
{
for(j=1;j<=N;j++)
{
if(i==N && j==N)
solution[i][j]=1;
printf("%d\t",solution[i][j]);
}
printf("\n");
}
}