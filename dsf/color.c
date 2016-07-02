#include<stdio.h>

int ctr=0;
int col[10]={0};

int colorplacement(int A[10][10],int vertex,int p,int n){
int j;
		for(j=1;j<=n;j++){
			if(A[vertex][j]==1){
				if(p==col[j])
					return 0;
			}
		
		}
		return 1;
}

int color(int A[10][10],int vertex,int m,int n){
	int p;
	
	if(ctr==n)
	return 1;
	
	for(p=1;p<=m;p++){
		if(colorplacement(A,vertex,p,n)==1){
			col[vertex]=p;
			ctr++;
			if(color(A,vertex+1,m,n)==1)
				return 1;
			col[vertex]=0;
			ctr--;
		}
	}
	return 0;
}



void main(){
int A[10][10],m,n,i,j;

printf("Enter the total number of vertices in the graph:");
scanf("%d",&n);

printf("Enter the chromatic number:");
scanf("%d",&m);

for(i=1;i<=n;i++){
	for(j=1;j<=n;j++){
		scanf("%d",&A[i][j]);
	}
}

color(A,1,m,n);

printf("The colors are:\n");
for(i=1;i<=ctr;i++){
printf("%d\t",col[i]);

}


}