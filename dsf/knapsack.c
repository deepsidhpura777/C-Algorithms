#include<stdio.h>                                                         /* Deep Sidhpura
																			 SE Comps Roll No 71.
																			 Batch=D*/
void main()
{
int weight[10],benefit[10],bw[10];
int n,size,i,j,keyw,keyb,keybw,cost=0,tempsize;
printf("Enter the capacity of the knapsack:");
scanf("%d",&size);
printf("Enter the no of items available:");
scanf("%d",&n);
printf("Enter the weight and its respective benefit:\n");
for(i=1;i<=n;i++)
{
	scanf("%d",&weight[i]);
	scanf("%d",&benefit[i]);
}
for(i=1;i<=n;i++)
{
	bw[i]=benefit[i]/weight[i];
}
for(j=2;j<=n;j++)
{
	keybw=bw[j];
	keyw=weight[j];
	keyb=benefit[j];
	i=j-1;
	while(i>0 && bw[i]<keybw)
	{
		weight[i+1]=weight[i];
		benefit[i+1]=benefit[i];
		bw[i+1]=bw[i];
		i--;
	}
	weight[i+1]=keyw;
	benefit[i+1]=keyb;
	bw[i+1]=keybw;
}

for(i=1;i<=n;i++)
{
	printf("\nWeight %d Benefit %d B/W %d \n",weight[i],benefit[i],bw[i]);
}
i=1;
printf("\nItem\tBenefit\tCost\tCapacity\n");
printf("%d\t%d\t%d\t%d\n",0,0,0,size);
while(size!=0)
{
	if(size-weight[i]>=0)
	{
		size=size-weight[i];
		cost=cost+benefit[i];
		printf("%d\t%d\t%d\t%d\n",weight[i],benefit[i],cost,size);
	}
	else
	{
		cost=cost+bw[i]*size;
		tempsize=size;
		size=0;
		printf("%d\t%d\t%d\t%d\n",tempsize,bw[i]*tempsize,cost,size);
	}
i++;
}
printf("The total cost is:%d",cost);








}