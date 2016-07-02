#include<stdio.h>
#include<conio.h>
//#include<alloc.h>
struct node
{
int data;
struct node *left;
struct node *right;
};

void create(struct node ** r,int n,char ch)
{
struct node *t=*r;
if(ch=='r')
{
if(t->right==NULL)
{
struct node *temp1=(struct node * )malloc(sizeof(struct node));
temp1->data=n;
temp1->left=NULL;
temp1->right=NULL;
t->right=temp1;
}
else
create(&(t->right),n,ch);
}
if(ch=='l')
{
if(t->left==NULL)
{
struct node *temp2=(struct node * )malloc(sizeof(struct node));
temp2->data=n;
temp2->left=NULL;
temp2->right=NULL;
t->left=temp2;
}
else
create(&(t->left),n,ch);
}
}


void displayin(struct node **r) //Left Root Right
{
struct node * t=*r;
if(t!=NULL)
{
displayin(&(t->left));
printf("%d\n",t->data);
displayin(&(t->right));
}
}

void displaypre(struct node **r) //Root Left right
{
struct node * t=*r;
if(t!=NULL)
{

printf("%d\n",t->data);
displaypre(&(t->left));
displaypre(&(t->right));
}
}

void displaypo(struct node **r) // Left Right Root
{
struct node * t=*r;
if(t!=NULL)
{
displaypo(&(t->left));
displaypo(&(t->right));
printf("%d\n",t->data);
}
}

void main()
{
struct node *root=NULL;
int ch,n;
char choice;
printf("1.Create\n2.Display Inorder\n3.Display Preorder\n4.Display Postorder\n");
 printf("Select your choice:\n");
 scanf("%d",&ch);

 while(ch!=0)
 {
    switch(ch)
    {
    case 1:printf("Enter number to add:\n");
	       scanf("%d",&n);
		   if(root==NULL)
		   {
		   root=(struct node * )malloc(sizeof(struct node));
		   root->data=n;
		   root->left=NULL;
		   root->right=NULL;
		   }
		   else
		   {
	        printf("Choose right or left:\n");
		    //scanf("%c",&choice);
		    choice=getche();
		    create(&root,n,choice);
		   } 
		  printf("\nAdded Successfully\n");
	break;
   case 2:displayin(&root);
	
	break;
   case 3:displaypre(&root);
	break;
   case 4:displaypo(&root);
	break;
   
   
 }
 printf("Select your choice:\n");
 scanf("%d",&ch);
 }



}