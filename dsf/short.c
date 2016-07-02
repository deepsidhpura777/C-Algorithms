#include<stdio.h>

void main(){

int W[10][10],A[10][10];

int i,j,k,n;

printf("Enter the total number of vertices:");
scanf("%d",&n);

printf("Enter the graph:\n");
for(i=1;i<=n;i++){
	for(j=1;j<=n;j++){
		scanf("%d",&W[i][j]);
		A[i][j]=W[i][j];
	}
}

for(k=1;k<=n;k++){
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			
			if(A[i][j] < (A[i][k] + A[k][j])){
				
				A[i][j]=A[i][j];
			}
			else
				A[i][j]=A[i][k] + A[k][j];
		}
	}
}

printf("The final matrix is:\n");
for(i=1;i<=n;i++){
	for(j=1;j<=n;j++){
		printf("%d\t",A[i][j]);
	
	}
	printf("\n");
}



}