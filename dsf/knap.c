#include<stdio.h>

void main(){

int B[10][10]={0,0};
int benefit[10];
int weight[10];
int n,i,w,W,k,ctr=0,cost=0;
int finalitems[10];

printf("Enter the number of items:");
scanf("%d",&n);

printf("Enter the required Weight:");
scanf("%d",&W);

printf("Enter the items and their weight:\n");
for(i=1;i<=n;i++){
scanf("%d",&weight[i]);
scanf("%d",&benefit[i]);
}

for(i=1;i<=n;i++)
B[i][0]=0;
for(w=1;w<=W;w++)
B[0][w]=0;

for(i=1;i<=n;i++){
	for(w=1;w<=W;w++){
		if(weight[i] <= w){
			if(benefit[i] + B[i-1][w - weight[i]] > B[i-1][w])
				B[i][w]=benefit[i] + B[i-1][w - weight[i]];
			else
				B[i][w]=B[i-1][w];
		}
		else
			B[i][w]=B[i-1][w];
	}
}

printf("\n");

for(i=0;i<=n;i++){
	for(w=0;w<=W;w++){
		printf("%d\t",B[i][w]);
	}
	printf("\n");
}



i=n;
k=W;



while(k>0 && i>0){

	if(B[i][k] != B[i-1][k]){
		finalitems[++ctr]=i;
		k=k-weight[i];
		i--;
	}
	else
	i--;
}

printf("The included items are:\n");
for(i=1;i<=ctr;i++){
	cost+=benefit[finalitems[i]];
	printf("Iten no:%d Weight:%d Benefit:%d\n",finalitems[i],weight[finalitems[i]],benefit[finalitems[i]]);
}
printf("Cost:%d",cost);

}