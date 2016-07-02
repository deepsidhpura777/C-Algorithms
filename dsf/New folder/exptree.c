#include<stdio.h>
#include<string.h>
struct node
{
char data;
struct node * left;
struct node * right;
};

struct node * stack[20];
int top=-1;

void push(struct node ** h)
{
stack[++top]=*h;
}

struct node * pop()
{
return stack[top--];
}

void display(struct node **h) // Left Root Right. ** means address of a pointer will be stored.
{
struct node * t=*h;
if(t!=NULL)
{
display(&(t->left));
printf("%c",t->data);
display(&(t->right));
}
}


int main()
{
char c[30],character;
struct node *temp;
temp=NULL;
printf("Enter the postfix expression:");
gets(c);
//puts(c);
int i;
for(i=0;i<strlen(c);i++)
{
character=c[i];
temp=(struct node * )malloc(sizeof(struct node));
temp->data=character;
temp->left=NULL;
temp->right=NULL;

if(character >= 'a' && character <= 'z') // ab+ -> a + b
{
push(&temp);
}

else
{
struct node * op1=pop();
struct node *op2=pop();
temp->right=op1;
temp->left=op2;
push(&temp);
}
}

display(&temp);

return 0;
}
