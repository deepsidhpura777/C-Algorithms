#include<stdio.h>
#include<string.h>
int i;
char firstchar;
char spre[100],spost[100];
int prefixTopostfix(char pre[100],char post[100])
{
static int c=0;
firstchar=pre[0];
if(firstchar>=97 && firstchar<=122)  //(a+b)*c -> *+abc -> ab+c*
{
post[c++]=firstchar;
return 1;
}
for(i=0;i<strlen(pre);i++)
{
spre[i]=pre[i+1];
}
int nextprefix1=prefixTopostfix(spre,post);
for(i=0;i<strlen(pre);i++)
{
spost[i]=pre[nextprefix1+1+i];
}
int nextprefix2=prefixTopostfix(spost,post);
post[c++]=firstchar;

return  nextprefix1+nextprefix2+1;

}

void main()
{
char pre[100];
char post[100];
int j;
printf("Enter the prefix expression:");
gets(pre);
printf("value:%d\n",prefixTopostfix(pre,post));
printf("The postfix expression is:");
puts(post);
puts(spre);
//puts(spost);
printf("%c",firstchar);
}
