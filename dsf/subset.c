#include<stdio.h>

int solution[10]={0},ctr=0,sum=0;

int subsetsum(int A[10],int i,int n,int N){


int j;

sum+=A[i];
solution[++ctr]=A[i];

	if(sum==n)
	return 1;
	
	if(sum < n){
	
		for(j=i+1;j<=N;j++){
		
			if(subsetsum(A,j,n,N)==1)
			return 1;
		
		}
		sum-=A[i];
		solution[ctr--]=0;
		return 0;
	}
	if(sum > n){
	
		sum-=A[i];
		solution[ctr--]=0;
		return 0;
	
	}
}



void main(){

int n,N,i,j,A[10],k;
printf("Enter the total numbers:");
scanf("%d",&N);
printf("Enter the required Number:");
scanf("%d",&n);
printf("Enter the numbers:\n");
for(i=1;i<=N;i++){
		scanf("%d",&A[i]);
}

for(i=1;i<=N;i++){
	k=subsetsum(A,i,n,N);
	if(k==1){
		printf("\nThe solution is:\n");
		for(j=1;j<=ctr;j++){
		printf("%d\t",solution[j]);
		}
		ctr=0;
		sum=0;
	}
}

/*printf("The solution is:\n");
for(i=1;i<=ctr;i++){
printf("%d\t",solution[i]);
}*/

}