#include<stdio.h>


void btree(int R[10][10],int i,int j){

if(i==j){
//printf("Leaf node\n");
return;
}
else{
printf("Left of %d:%d\n",R[i][j],R[i][R[i][j]-1]);
printf("Right of %d:%d\n",R[i][j],R[R[i][j]][j]);
btree(R,i,R[i][j]-1);
btree(R,R[i][j],j);
}


}

void main(){

int F[10];
int P[10][10]={0,0},W[10][10]={0,0},R[10][10]={0,0};
int n;
int i,j,k;
int tempindex,min=1000,s,diff=2;

printf("Enter the no of nodes:");
scanf("%d",&n);

printf("Enter the Frequencies:");
for(i=1;i<=n;i++)
scanf("%d",&F[i]);

for(i=0;i<=n;i++){
	for(j=0;j<=n;j++){
		for(k=i+1;k<=j;k++){
				P[i][j]+=F[k];
			}
	}
}



for(i=0;i<n;i++){
	W[i][i+1]=F[i+1];
	R[i][i+1]=i+1;
}

for(i=0;i<=n;i++){
for(j=0;j<=n;j++){
printf("%d\t",P[i][j]);
}
printf("\n");
}

	i=0;
	while(diff<=n){
		
		j=i+diff;
		for(k=i+1;k<=j;k++){
			
			s=W[i][k-1] + W[k][j];
			if(s<min){
				
				min=s;
				tempindex=k;
			}
			s=0;
		}
		
		W[i][j]=P[i][j]+min;
		R[i][j]=tempindex;
		
		i++;
		min=1200;
		
		if(i>(n-diff)){
			i=0;
			diff++;
		}
	}

printf("\n");

for(i=0;i<=n;i++){
for(j=0;j<=n;j++){
printf("%d\t",W[i][j]);
}
printf("\n");
}
printf("\n");
for(i=0;i<=n;i++){
for(j=0;j<=n;j++){
printf("%d\t",R[i][j]);
}
printf("\n");
}
printf("\nRoot:%d\n",R[0][n]);
btree(R,0,n);


}