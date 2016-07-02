#include<stdio.h>
void main(){

int a[6],i,j=1,temp;
printf("Enter 5 numbers:");
for(i=1;i<=5;i++){

scanf("%d",&a[i]);

}

while(j <= 5){

if(a[j] > a[j+1]){

temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
j=1;

}

else{

j++;

}

}

printf("The sorted numbers are:\n");
for(i=1;i<=5;i++)
printf("%d\t",a[i]);


}