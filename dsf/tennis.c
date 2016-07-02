#include<stdio.h>

int * ten(int * a,int n){
	
	int *b11,*b12,*b21,*b22;
	int i,j,c=0;
	
	if(n==2){
	
		*a=2;
		*(a+8)=1;
		
		return a;
	}
	else{
	
		b11=ten(a,n/2);
		b21=b11+(n/2)*8;
		b12=b11+(n/2)-1;
		b22=b21+(n/2)-1;
		
		for(j=0;j<n/2-1;j++){
		
			for(i=0;i<n/2;i++){
		
			*(b21+j+i*8)=*(b11+j+i*8)+n/2;
			}
		}
		
		for(j=0;j<n/2;j++){
		
			for(i=0;i<n/2;i++){
			
				if(j==0){
				
				*(b12+j+i*8)=n/2+1+c;
				c++;
				
				}
				else{
					
					if(*(b12+j-1+i*8)==n)
					*(b12+j+i*8)=n/2 + 1;
					
					else
					*(b12+j+i*8)=*(b12+j-1+i*8)+1;
				}
			}
		}
		c=0;
		for(j=0;j<n/2;j++){
		
			for(i=0;i<n/2;i++){
			
				if(j==0){
				
				*(b22+j+i*8)=++c;
				
				
				}
				else{
					
					if(*(b22+j-1+i*8)==1)
					*(b22+j+i*8)=n/2;
					
					else
					*(b22+j+i*8)=*(b22+j-1+i*8)-1;
				}
			}
		}
		
		return b11;
	}
}




void main(){
	
	int a[8][8],n,i,j;
	int *b;
	printf("Enter the value of n:");
	scanf("%d",&n);
	
	b=ten(&a[0][0],n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
		
			printf("%d\t",a[i][j]);
		
		}
		printf("\n");
	}
	
	
	
	
}