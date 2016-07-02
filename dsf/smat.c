#include<stdio.h>							/*Deep Sidhpura
											  Rollno 71 SE Comps*/

void mul(int *a,int *b,int *c,int n){


		int *A11,*A12,*A21,*A22;
		int *B11,*B12,*B21,*B22;
		int *C11,*C12,*C21,*C22;
		int Q1,Q2,Q3,Q4,Q5,Q6,Q7;
		
	if(n==2){
		
		Q1=(*a + *(a+9))*(*b + *(b+9));
		Q2=(*(a+8) + *(a+9))*(*b);
		Q3=(*a) * (*(b+1) - *(b+9));
		Q4=*(a+9)*(*(b+8) - *b);
		Q5=(*a + *(a+1))*(*(b+9));
		Q6=(*(a+8) - *a)*(*b + *(b+1));
		Q7=(*(a+1) - *(a+9))*(*(b+8) + *(b+9));
		
		(*c)=(*c)+(Q1+Q4-Q5+Q7);
		*(c+1)=*(c+1)+(Q3+Q5);
		*(c+8)=*(c+8)+(Q2+Q4);
		*(c+9)=*(c+9)+(Q1+Q3-Q2+Q6);
	}
	else{
	
		A11=a;
		A12=A11+(n/2);
		A21=A11+(n/2)*8;
		A22=A21+(n/2);
		
		B11=b;
		B12=B11+(n/2);
		B21=B11+(n/2)*8;
		B22=B21+(n/2);
		
		C11=c;
		C12=C11+(n/2);
		C21=C11+(n/2)*8;
		C22=C21+(n/2);
		
		
		mul(A11,B11,C11,n/2);
		mul(A12,B21,C11,n/2);
		mul(A11,B12,C12,n/2);
		mul(A12,B22,C12,n/2);
		mul(A21,B11,C21,n/2);
		mul(A22,B21,C21,n/2);
		mul(A21,B12,C22,n/2);
		mul(A22,B22,C22,n/2);
		


		
	}
	
}


void main(){

	int a[8][8],b[8][8],c[8][8];
	int n,i,j;
	int e=0,d=0;
	
	printf("Enter the value of n:");
	scanf("%d",&n);
	//printf("Enter elements of A:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
	
			a[i][j]=e++;
			b[i][j]=d++;
			c[i][j]=0;
		
		}
	}
    
	printf("\nMatrix 1:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
	
		printf("%d\t",a[i][j]);
		
		}
		printf("\n");
	}
	
	printf("\nMatrix 2:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
	
		printf("%d\t",a[i][j]);
		
		}
		printf("\n");
	}
	
	
	printf("\n");
	
	mul(&a[0][0],&b[0][0],&c[0][0],n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		
			printf("%d\t",c[i][j]);
		
		}
		printf("\n");
	}
	
	
	
	
}