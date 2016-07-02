#include<stdio.h>

struct node
{
	int data;
	int degree;
	int flag;
	struct node * nextLink;
};

void createPol(struct node ** h,int c,int d)
{
	    struct node * visitptr=*h;
		struct node * temp;
		while(visitptr->nextLink!=NULL)
		{
			visitptr=visitptr->nextLink;
		}
	
		temp=(struct node * )malloc(sizeof(struct node));
		temp->data=c;
		temp->degree=d;
		temp->flag=0;
		temp->nextLink=NULL;
		visitptr->nextLink=temp;
}

void display(struct node ** h)
{
	struct node * t=*h;
	while(t!=NULL)
	{
		printf("coeff:%d ",t->data);
		printf("degree:%d\n",t->degree);
		t=t->nextLink;
	}
	
}

struct node * add(struct node ** h1, struct node ** h2)
{
struct node *t1,*t2;
t1=*h1;
t2=*h2;
int ctr=0;
struct node * visitptr;
struct node * temp,*root;
	while(t1!=NULL)
	{
		while(t2!=NULL)
		{
			if(t1->degree==t2->degree)
			{
				ctr++;
				if(ctr==1)
				{
					root=(struct node * )malloc(sizeof(struct node));
					root->data=(t1->data)+(t2->data);
					root->degree=t1->degree;
					root->nextLink=NULL;
					t1->flag=1;
					t2->flag=1;
					visitptr=root;
				}
				else
				{
					temp=(struct node * )malloc(sizeof(struct node));
					temp->data=(t1->data)+(t2->data);
					temp->degree=t1->degree;
					temp->nextLink=NULL;
					t1->flag=1;
					t2->flag=1;
					visitptr->nextLink=temp;
					visitptr=temp;
				}
			}
			
			t2=t2->nextLink;
		}
		t1=t1->nextLink;
		t2=*h2; // Very Important step
	}
	
	t1=*h1;
	t2=*h2;
	
	while(t1!=NULL)
	{
		if(t1->flag==0)
		{
			temp=(struct node * )malloc(sizeof(struct node));
			temp->data=t1->data;
			temp->degree=t1->degree;
			temp->nextLink=NULL;
			visitptr->nextLink=temp;
			visitptr=temp;
			
		}
		t1=t1->nextLink;
	}
	
	while(t2!=NULL)
	{
		if(t2->flag==0)
		{
			temp=(struct node * )malloc(sizeof(struct node));
			temp->data=t2->data;
			temp->degree=t2->degree;
			temp->nextLink=NULL;
			visitptr->nextLink=temp;
			visitptr=temp;
		}
		t2=t2->nextLink;
	}
return root;
}

void main()
{
struct node * head1,*head2,*root;
head1=NULL;
head2=NULL;
root=NULL;
int choice,c;
int coeff,deg;
printf("1.Enter 1st Polynomial\n2.Enter Second Polynomial\n3.Display 1\n4.Display 2\n5.Add");
scanf("%d",&choice);
while(choice !=0)
{
switch(choice)
{
case 1:
		do

   {
       printf("Enter coefficient and degree:");
       scanf("%d",&coeff);
	   scanf("%d",&deg);
	   if(head1==NULL)
	   {
	   head1=(struct node * )malloc(sizeof(struct node));
	   head1->data=coeff;
	   head1->degree=deg;
	   head1->flag=0;
	   head1->nextLink=NULL;
	   }
	   else
	   {
       createPol(&head1,coeff,deg);
	   }
       printf("Press 1 to add more and 0 to stop");
	   scanf("%d",&c);
    }
	   while(c!=0);
break;
case 2:do
	   {
       printf("Enter coefficient and degree:");
       scanf("%d",&coeff);
	   scanf("%d",&deg);
	   if(head2==NULL)
	   {
	   head2=(struct node * )malloc(sizeof(struct node));
	   head2->data=coeff;
	   head2->degree=deg;
	   head2->flag=0;
	   head2->nextLink=NULL;
	   }
	   else
	   {
       createPol(&head2,coeff,deg);
	   }
	   printf("Press 1 to add more and 0 to stop:");
	   scanf("%d",&c);
       }
	   while(c!=0);
break;

case 3://printf("Head is:%d",head1->data);
	   printf("1st Polynomial is:\n");
       display(&head1);
break;

case 4:printf("2nd Polynomial is:\n");
	   display(&head2);
break;

case 5:root=add(&head1,&head2);
       printf("The addition is:\n");
       display(&root);
break;
}
printf("Select your choice:");
scanf("%d",&choice);
}
}