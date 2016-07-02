#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
char list[50],sign;
float store[50],stack[50],op1,op2,result;
int i,j=0,top=-1,s=0,c=0;

printf("Enter the expression:");
gets(list);

for(i=0;i<strlen(list);i++)
{
//if(list[i]!= 43 || list[i]!= 45 || list[i]!= 42 || list[i]!= 47)
if(list[i] >= 97 && list[i] <=122)
{
printf("Enter the value of %c:",list[i]);
scanf("%f",&store[j]);
j++;
}
}

for(i=0;i<strlen(list);i++)
{
//if(list[i]!=43 || list[i]!=45 || list[i]!=42 || list[i]!=47)
if(list[i] >= 97 && list[i] <=122)
{
s++;
}
else
{
sign=list[i];
while(s>=1)
{
top++;
stack[top]=store[c];
c++;s--;
}

op1=stack[top];
op2=stack[top-1];

if(sign=='+')
result=op1+op2;

if(sign=='-')
result=op1-op2;

if(sign=='*')
result=op1*op2;

if(sign=='/')
result=op2/op1;

top--;
stack[top]=result;

}

}

printf("%f",result);

}