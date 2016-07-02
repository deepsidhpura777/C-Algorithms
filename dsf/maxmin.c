#include<stdio.h>

struct pair{

	int min;
	int max;

};

struct pair sol,low,high;  

struct pair maxmin(int a[10],int i,int j){

int mid;

if(i==j){

sol.max=a[i];
sol.min=a[i];

return sol;
}

else if(i==j-1){

	if(a[i]<a[j]){
		sol.max=a[j];
		sol.min=a[i];
		
		
	}
	
	else{
		sol.max=a[i];
		sol.min=a[j];
	}
return sol;
}

else{


mid=(i+j)/2;
low=maxmin(a,i,mid);
high=maxmin(a,mid+1,j);


if(low.max > high.max)
sol.max=low.max;

else
sol.max=high.max;

if(low.min < high.min)
sol.min=low.min;

else
sol.min=high.min;

return sol;
}

}


void main(){

int n,a[10],i;
printf("Enter the number of elements:");
scanf("%d",&n);
printf("Enter the respective elements:");
for(i=1;i<=n;i++){

scanf("%d",&a[i]);

}

maxmin(a,1,n);

printf("Max:%d Min:%d",sol.max,sol.min);



}