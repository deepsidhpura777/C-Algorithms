#include<stdio.h>

long int p[400000][10];
static int K=0;

void swap(int * x,int * y){
	
	int temp=*x;
	*x=*y;
	*y=temp;
}

void permut(int * a,int i,int n){
	
	int j;
	if(i==n){
		
		for(j=0;j<=n;j++){
			p[K][j]=*(a+j);
		}
		K++;
	}
	
	else{
		
		for(j=i;j<=n;j++){
		
			swap(a+i,a+j);
			permut(a,i+1,n);
			swap(a+i,a+j);
		}
	}
}




void main(){
	
	int a[20],i,j,n,min=1000,index,c=0;
	int A[20][20],cost[500000]={0};
	printf("Enter the value of n:");
	scanf("%d",&n);
	printf("Enter the vertices:\n");
	for(i=0;i<n;i++){
		
		scanf("%d",&a[i]);
	}
	
	printf("Enter the cost matrix:\n");
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&A[i][j]);
			c++;
		}
	}
	
	
	printf("\nThe ans is:\n");
	
	permut(&a[1],0,n-2);
	
	
	
	
	
	for(i=0;i<K;i++){
		for(j=0;j<n;j++){
		
			if(j==0){
			cost[i]+= A[1][p[i][j]];
			}
			
			else if(j==n-1){
			cost[i]+= A[p[i][j-1]][1];
			}
			
			else{
			cost[i]+=A[p[i][j-1]][p[i][j]];
			}
		}
		
		if(cost[i]<=min){
			min=cost[i];
			index=i;
		}
	
	}
	
	printf("\nThe total no of combinations:%d\n",K);
	
	printf("The minimum cost is:%d\n",min);
	printf("1\t");
	for(i=0;i<n-1;i++){
	printf("%d\t",p[index][i]);
	}
	printf("1\t");
	printf("\n");
}