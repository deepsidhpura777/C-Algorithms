#include<stdio.h>


struct node
{
int data;
struct node * nextLink;
};


void create(struct node ** h,int n)
{
	struct node * visitptr=*h;
	struct node * temp;
	while(visitptr->nextLink!=NULL)
		visitptr=visitptr->nextLink;
		
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=n;
	temp->nextLink=NULL;
	visitptr->nextLink=temp;
}

void insert(struct node **h,int n,int p)
{
	struct node * visitptr=*h;
	struct node * temp,*prev,*next;
	int c=1;
	while(c<p)
	{
		c++;
		prev=visitptr;
		visitptr=visitptr->nextLink; // [prev -> visit -> next] then visit becomes prev,visit becomes visit->next and next becomes new visit's next ->
		next=visitptr->nextLink;  //moves 2 pointers forward.
	}
	
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=n;
	prev->nextLink=temp;
	temp->nextLink=visitptr;
}

void sort(struct node ** h) //bubble sort on linked lists
{
	struct node *visitptr=*h;
	while(visitptr->nextLink!= NULL)
	{
		if( (visitptr->data) > (visitptr->nextLink)->data )
		{
			int temp=visitptr->data;
			visitptr->data=(visitptr->nextLink)->data;
			(visitptr->nextLink)->data=temp;
			visitptr=*h;
		}
		else
		visitptr=visitptr->nextLink;
	}


}

void display(struct node ** h)
{

	struct node * visitptr=*h;
	printf("The sorted list is:\n");
	while(visitptr!=NULL)
	{
		printf("%d\n",visitptr->data);
		visitptr=visitptr->nextLink;
	}

}

void main()
{
struct node * head;
head=NULL;
int n,i,p;
int choice,ch;
printf("1.Enter Elements\n2.Sort\n3.Insert\n4.Display\n");
scanf("%d",&ch);
while(ch!=0)
{
switch(ch)
{

case 1:	printf("Enter 1 to enter the elements and 0 to stop");
		scanf("%d",&choice);

		while(choice!=0)
		{
			printf("Enter the element:");
			scanf("%d",&n);
			if(head==NULL)
			{
				head=(struct node *)malloc(sizeof(struct node));
				head->data=n;
				head->nextLink=NULL;
	
			}
			else
			{
				create(&head,n);
			}
			printf("Select your choice:");
			scanf("%d",&choice);
			
		}
break;
case 2:sort(&head);
break;

case 3:printf("Enter the element to insert and its position:");
       scanf("%d",&i);
	   scanf("%d",&p);
	   insert(&head,i,p);
	   display(&head);
break;
case 4:
		sort(&head);
		display(&head);
break;

}
printf("Select your option:");
scanf("%d",&ch);
}
}
