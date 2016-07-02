#include<stdio.h>                                                          							/* Deep Sidhpura
																			 SE Comps Roll No 71.
																			 Batch=D*/

static int conn[20][20]={0,0};
int n;
struct graph{
	
	int v1;
	int v2;
	int c;
};

void dfs(int vertex1,int vertex2){
    int k;
	for(k=1;k<=n;k++){
	
		if(k!=vertex1 || k!=vertex2){
		
			if(conn[vertex1][k]==1 && conn[vertex2][k]==0){
			
				conn[vertex2][k]=1;
				conn[k][vertex2]=1;
				dfs(k,vertex2);
				
			}
		}		
	}
}

void main(){

	struct graph G[20],S[20],temp;
	int taken[20]={0};
	
	int e,i,j;
	int cost=0,selected=0,flag=0;
	printf("Enter the total no of nodes:");
	scanf("%d",&n);
	printf("Enter the total no of edges:");
	scanf("%d",&e);
	printf("Enter the respective vertices and cost:\n");
	for(i=1;i<=e;i++){
		
		scanf("%d",&G[i].v1);
		scanf("%d",&G[i].v2);
		scanf("%d",&G[i].c);
	}
	
	for(j=2;j<=e;j++){
	
		temp=G[j];
		i=j-1;
		while(i>0 && G[i].c > temp.c){
		
			G[i+1]=G[i];
			i--;
		}
		G[i+1]=temp;
	}
	
	for(i=1;i<=e;i++){
	
		if(!(taken[G[i].v1]==1 && taken[G[i].v2]==1)){
			
			S[++selected]=G[i];
			taken[G[i].v1]=1;
			taken[G[i].v2]=1;
			conn[G[i].v1][G[i].v2]=1;
			conn[G[i].v2][G[i].v1]=1;
			cost+=G[i].c;
			
			dfs(G[i].v1,G[i].v2);
			dfs(G[i].v2,G[i].v1);
		}
		else{
		
			for(j=1;j<=n;j++){
			
				if(G[i].v1 != j || G[i].v2 != j){
			
				if((conn[G[i].v1][j]==1 && conn[G[i].v2][j]==1)){
				
					flag=1;
					break;
				
				}
				}
			}
			    if(flag==0){
				
					S[++selected]=G[i];
					taken[G[i].v1]=1;
					taken[G[i].v2]=1;
					conn[G[i].v1][G[i].v2]=1;
					conn[G[i].v2][G[i].v1]=1;
					cost+=G[i].c;
					dfs(G[i].v1,G[i].v2);
					dfs(G[i].v2,G[i].v1);
				}
				
			
		}
	flag=0;	
//add else condition where both are taken and test the connectivity of selected tree uptil now,if it forms a circuit.
	}
	/*for(i=1;i<=n;i++){
	
		for(j=1;j<=n;j++){
		
			printf("%d\t",conn[i][j]);
			
		}
		printf("\n");
	
	}*/
	
	printf("The Tree is:\n");
	for(i=1;i<=selected;i++){
	
		printf("[%d-%d] = %d\n",S[i].v1,S[i].v2,S[i].c);
	}
	printf("The total cost is:%d",cost);
}