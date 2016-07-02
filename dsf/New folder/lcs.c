#include<stdio.h>
#include<string.h>

void display(char a[],int d[][25],int m,int n){

		if(m==0 || n==0)
			return;
	
		if(d[m][n]==7){
		
			display(a,d,m-1,n-1);
			printf("%c",a[m-1]);
		}
		else if(d[m][n]==8){
			
			display(a,d,m-1,n);
		}
		else{
			
			display(a,d,m,n-1);
		}
	

}


void main(){

char a[25],b[25];
int m,n,i,j;
int c[25][25]={0,0},d[25][25]={0,0};

printf("Enter the first string:");
scanf("%s",a);
printf("Enter the second string:");
scanf("%s",b);

m=strlen(a);
n=strlen(b);

for(i=0;i<=m;i++){

	c[i][0]=0;
	for(j=0;j<=n;j++){
	
		c[0][j]=0;
	}
}

for(i=1;i<=m;i++){

	for(j=1;j<=n;j++){
		
		if(a[i-1]==b[i-1]){
		
			c[i][j]=c[i-1][j-1]+1;
			d[i][j]=7; //for diagonal up arrow
		}
		else if(c[i-1][j]>=c[i][j-1]){
		
			c[i][j]=c[i-1][j];
			d[i][j]=8; // for up arrow
		}
		else
		{
		
			c[i][j]=c[i][j-1];
			d[i][j]=4;  // for left arrow
		}
	}
}

for(i=0;i<=m;i++){

	for(j=0;j<=n;j++){
	
		printf("%d\t",c[i][j]);
	}
	printf("\n");
}
display(a,d,m,n);


}