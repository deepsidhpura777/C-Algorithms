#include<stdio.h>											//Deep Sidhpura
															//SE Computers Roll no 71

int checkPlacement(int A[10][10],int row,int col,int n){
	
	int i,j;
	for(i=1;i<row;i++){
		if(A[i][col])
			return 0;
	}
	
	for(i=row,j=col;j>=1 && i>=1 ;i--,j--){
		if(A[i][j])
			return 0;
	}
	
	for(i=row,j=col;j<=n && i>=0 ;i--,j++){
		if(A[i][j])
			return 0;
	}
	
	return 1;
	

}

int nQueen(int A[10][10],int i,int n){
static int ctr;
int p;

	if(ctr==n){
		return 1;
	}
	
	for(p=1;p<=n;p++){
		
		if(checkPlacement(A,i,p,n)==1){
			
			A[i][p]=1;
			ctr++;
			
			if(nQueen(A,i+1,n)==1)
				return 1;
				
			A[i][p]=0;
			ctr--;
		}
	}
	return 0 ;
}


void main(){

int n,i,j;
int ans=0;
int A[10][10]={0,0};
printf("Enter the value of n:");
scanf("%d",&n);
if(n<=2)
printf("The solution cannot be obtained\n");

else
ans=nQueen(A,1,n);

if(ans){
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			
			printf("%d\t",A[i][j]);
		}
		printf("\n");
	
	}
	
}



}