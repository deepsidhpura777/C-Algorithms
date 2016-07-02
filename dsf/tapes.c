#include<stdio.h>

int comb[10][10],ctr=0;

void swap(int * x,int * y){

int temp=*x;
*x=*y;
*y=temp;
}


void permut(int *a,int i,int n){    //Finding out permutations of all files.
int j,k;
	if(i==n){
		ctr++;
		for(k=0;k<=n;k++){
			comb[ctr][k]=*(a+k);   //Storing all combinations
		}
	}

for(j=i;j<=n;j++){

	swap(a+i,a+j);
	permut(a,i+1,n);
	swap(a+i,a+j);
}
}



void main(){

int a[10],length[10],n,i,j,tempcost=0,min=1000,index,cost[10];
printf("Enter the number of tapes:");
scanf("%d",&n);
printf("Enter the tape no and its length:\n");
for(i=1;i<=n;i++){
	scanf("%d",&a[i]);
	scanf("%d",&length[i]);
}

permut(&a[1],0,n-1);
printf("CTR:%d\n",ctr);




for(i=1;i<=ctr;i++){
	for(j=0;j<n;j++){
		tempcost+=(length[comb[i][j]] * (n-j));  // Calculation of the cost of each combination
	}
	cost[i]=tempcost;
	if(tempcost < min){
		min=tempcost;
		index=i;
	}
	tempcost=0;
}

printf("The combinations are:\n");

for(i=1;i<=ctr;i++){
	for(j=0;j<n;j++){
		printf("%d\t",comb[i][j]);
	}
	printf("Cost:%d",cost[i]);
	printf("\n");
}

printf("The minimum cost is:%d\n",min);
printf("The pattern is:\n");
for(j=0;j<n;j++)
printf("%d\t",comb[index][j]);









}
