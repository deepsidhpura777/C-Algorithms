#include<stdio.h>
#include<stdlib.h>
int main()
{
    int nop=56,nor=56,k,i,j,count=0,t=0,flag=0,finish[56];
    int allocation[56][56];
    int s[56],claim[56][56],work[56],available[56],need[56][56];
    for(i=0;i<nop;i++)
    {
        for(j=0;j<nor;j++){
            claim[i][j]=rand()%50;
        }

    }
    for(i=0;i<nop;i++)
    {
        for(j=0;j<nor;j++){
                  allocation[i][j]=rand()%30;
                while(allocation[i][j]>claim[i][j])
                           allocation[i][j]=rand()%30;
               need[i][j]=claim[i][j]-allocation[i][j];
        }

    }
    for(i=0;i<nor;i++)
    {
        available[i]=rand()%10;
    }

for(k=0;k<nop;k++)
{
  finish[k]=0;
}

while(count<nop)
{
 for(k=0;k<nop;k++)
 {
   if(finish[k]==0)
  {
  for(i=0;i<nor;i++)
  {

   if(need[k][i]<=available[i])
   {
    flag=1;
     if(flag==1)
    {
     available[i]=available[i]+allocation[k][i];
     count=count+1;
     finish[k]=1;
     s[t++]=k;
     }
  break;
 }break;
 }
}
}}
printf("\nSafe Sequence is:\n");

    for(i=0;i<nop;i++)
        printf("\tP%d",s[i]);
    printf("\n");
return 0;
}
