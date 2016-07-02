#include<stdio.h>                                                         								/* Deep Sidhpura
																			 SE Comps Roll 71.
																			 Batch=D*/

static int conn[20][20]={0,0};
int n;
struct graph{
	
	int v1;
	int v2;
	int c;
	int included;
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

	struct graph G[20],S[20],temp,t;
	int taken[20]={0};
	
	int e,i,j,start,vertex1,vertex2,tempindex;
	int cost=0,flag=0,countvertex=0,min=100;
	static int selected=0;
	printf("Enter the total no of nodes:");
	scanf("%d",&n);
	printf("Enter the total no of edges:");
	scanf("%d",&e);
	printf("Enter the respective vertices and cost:\n");
	for(i=1;i<=e;i++){
		
		scanf("%d",&G[i].v1);
		scanf("%d",&G[i].v2);
		scanf("%d",&G[i].c);
		G[i].included=0;
	}
	printf("Enter the starting vertex:");
	scanf("%d",&start);
	
	for(j=2;j<=e;j++){
	
		t=G[j];
		i=j-1;
		while(i>0 && G[i].c > t.c){
		
			G[i+1]=G[i];
			i--;
		}
		G[i+1]=t;
	}
	
	for(i=1;i<=e;i++){
	
		if(G[i].v1==start || G[i].v2==start){
		
			S[++selected]=G[i];
			G[i].included=1;
			conn[G[i].v1][G[i].v2]=1;
			conn[G[i].v2][G[i].v1]=1;
			if(taken[G[i].v1]==0){
			
				countvertex++;
				taken[G[i].v1]=1;
			}
			if(taken[G[i].v2]==0){
			
				countvertex++;
				taken[G[i].v2]=1;
			}
			cost+=G[i].c;
			
			break;
		}
	}
	
	
	while(countvertex<n){
	
		for(i=1;i<=n;i++){
	
			for(j=1;j<=n;j++){
		
				printf("%d\t",conn[i][j]);
			
			}
			printf("\n");
	
		}
	
	    
		for(i=1;i<=selected;i++){
		
			vertex1=S[i].v1;
			vertex2=S[i].v2;
			for(j=1;j<=e;j++){
			
				if(G[j].included==0){
			
					if((G[j].v1==vertex1 || G[j].v2==vertex2 || G[j].v1==vertex2 || G[j].v2==vertex1)){
				
						if(G[j].c < min){
						
							min=G[j].c;
							temp=G[j];
							tempindex=j;
						}
				    }
				}	
			}
		}
		
	
		if(!(taken[temp.v1]==1 && taken[temp.v2]==1)){
			
			S[++selected]=G[tempindex];
			G[tempindex].included=1;
			conn[G[tempindex].v1][G[tempindex].v2]=1;
			conn[G[tempindex].v2][G[tempindex].v1]=1;
			if(taken[G[tempindex].v1]==0){
			
				countvertex++;
				taken[G[tempindex].v1]=1;
			}
			if(taken[G[tempindex].v2]==0){
			
				countvertex++;
				taken[G[tempindex].v2]=1;
			}
			cost+=G[tempindex].c;
			
			dfs(G[tempindex].v1,G[tempindex].v2);
			dfs(G[tempindex].v2,G[tempindex].v1);
			
		}
		else{
		
			for(j=1;j<=n;j++){
			
				if(G[tempindex].v1 != j || G[tempindex].v2 != j){
			
				if((conn[G[tempindex].v1][j]==1 && conn[G[tempindex].v2][j]==1)){
				
					flag=1;
					break;
				
				}
				}
			}
			    if(flag==0){
				
					S[++selected]=G[tempindex];
					G[tempindex].included=1;
					conn[G[tempindex].v1][G[tempindex].v2]=1;
					conn[G[tempindex].v2][G[tempindex].v1]=1;
					cost+=G[tempindex].c;
					dfs(G[tempindex].v1,G[tempindex].v2);
					dfs(G[tempindex].v2,G[tempindex].v1);
				}
				if(flag==1){
				
					G[tempindex].included=1;
				}
				
			
		}
	printf("\n");
	flag=0;	
	
	min=100;
	
	
	
//add else condition where both are taken and test the connectivity of selected tree uptil now,if it forms a circuit.
	}
	
	for(i=1;i<=n;i++){
	
			for(j=1;j<=n;j++){
		
				printf("%d\t",conn[i][j]);
			
			}
			printf("\n");
	}
	
	printf("The Tree is:\n");
	for(i=1;i<=selected;i++){
	
		printf("[%d-%d] = %d\n",S[i].v1,S[i].v2,S[i].c);
	}
	printf("The total cost is:%d",cost);
}