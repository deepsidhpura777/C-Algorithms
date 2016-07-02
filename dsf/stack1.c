#include<stdio.h>
//#include<conio.h>
#include<string.h>

//int precin(char);
//int precout(char);
 int precin(char sign)
 {
   switch(sign)
   {
	case '#': return 0;
	case '+': return 2;
	case '-': return 2;
	case '(': return 1;
	case ')':return 0;
	case '*': return 3;
	case '/':return 3;
   }
}

int precout(char sign)
 {
	switch(sign)
	{
       case '#': return 0;
	case '+': return 2;
	case '-': return 2;
	case '(': return 4;
	case ')':return 0;
	case '*':return 3;
	case '/':return 3;
	}
}

void main()
{
char list[50],stack[50],signin,signout,result[50];
int i,top,c;
//clrscr();
top=0;c=0;
stack[top]='#';

printf("Enter an Expression:");
gets(list);

for(i=0;i<strlen(list);i++)
{
  if(list[i] >='a' && list[i]<='z')
   {
     result[c]=list[i];
     c++;
   }

else
{
    signout=list[i];
    signin=stack[top];

if((precin(signin)>precout(signout)) && signin!='(')
{
result[c]=signin;
c++;
stack[top]=signout;
}

else
{
top++;
stack[top]=signout;
}

}

}

while(top!=0)
{
if(stack[top]!='(' && stack[top]!=')')
{
result[c]=stack[top];
c++;
}
top--;
}

for(i=0;i<c;i++)
printf("%c",result[i]);
//getch();
}

