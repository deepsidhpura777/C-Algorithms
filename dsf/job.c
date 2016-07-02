#include<stdio.h>

void main(){

int deadline[10];
int profit[10];
int sequence[10]={0};
int n,i,j,keyd,keyp,ctr=0,max=0;

printf("Enter the no of jobs:");
scanf("%d",&n);
printf("Enter the profits and the respective deadlines:\n");
for(i=1;i<=n;i++){
	scanf("%d",&profit[i]);
	scanf("%d",&deadline[i]);
}

for(j=2;j<=n;j++){
	keyp=profit[j];
	keyd=deadline[j];
	i=j-1;
	while(i>0 && profit[i] < keyp){
		profit[i+1]=profit[i];
		deadline[i+1]=deadline[i];
		i--;
	}
	
	profit[i+1]=keyp;
	deadline[i+1]=keyd;
}

printf("\n");
for(i=1;i<=n;i++){
printf("%d %d \n",profit[i],deadline[i]);

}

for(i=1;i<=n;i++){
	//printf("Deadline of i:%d\n",deadline[i]);
	if(sequence[deadline[i]]==0){
		sequence[deadline[i]]=profit[i];
		max+=profit[i];
		ctr++;
		//printf("Sequence array and count:%d %d\n",sequence[i],ctr);
	}
	else{
		for(j=deadline[i];j>0;j--){
		
			if(sequence[j]==0){
			
				sequence[j]=profit[i];
				max+=profit[i];
				ctr++;
				//printf("Sequence array and count:%d %d\n",sequence[i],ctr);
				break;
			}
		}
	}
}

printf("The sequence is:\n");
for(i=1;i<=ctr;i++){
printf("%d\n",sequence[i]);
}
printf("Profit:%d",max);

}