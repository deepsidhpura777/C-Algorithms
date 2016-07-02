#include<stdio.h>
 
 struct node
 {
 int data;
 struct node *previousLink;
 struct node *nextLink;
 };
 
 struct node * top;
 struct node *rear;
 struct node *front;
 
 void pushstack(struct node **h,int n) //storing this way: top->(top-1)->......
 {
 struct node * t = *h;
 static int c=0;
 c++;
 if(c==1)
 {
 struct node *temp1=(struct node * )malloc(sizeof(struct node));
 temp1->data=n;
 temp1->nextLink=t;
 top=temp1;
 }
 else
 {
 struct node *temp2=(struct node * )malloc(sizeof(struct node));
 temp2->data=n;
 temp2->nextLink=top;
 top=temp2;
 }
 }
 
 
 int popstack()
 {
 if(top==NULL)
 {
 printf("Stack empty\n");
 return 0;
 }
 else
 {
 int d=top->data;
 top=top->nextLink;
 return d;
 }
 }
 
void pushq(struct node **h,int n)  //rear -> next elemrnt ->front;[next pointer]
								   //rear <- next element <-front;[previous pointer]
 {
 struct node *t= *h;
 static int c=0;
 c++;
 if(c==1)
 {
 struct node *temp1=(struct node * )malloc(sizeof(struct node));
 temp1->data=n;
 temp1->nextLink=t;
 rear=temp1;
 t->previousLink=temp1;    //This is required so that front can access the nodes while popping
 temp1->previousLink=NULL;
 }
 else
 {
 struct node *temp2=(struct node * )malloc(sizeof(struct node));
 temp2->data=n;
 temp2->nextLink=rear;
 rear->previousLink=temp2;
 rear=temp2;
 temp2->previousLink=NULL;
 }
 }
 
 int popq()
 { 
    if(front==NULL)
	{
	printf("Queue Empty\n");
	return 0;
	}
   else
   {
   int d=front->data;
   front=front->previousLink;
   return d;
   }
 }
 
 void main()
 {
 struct node * head=NULL;
 struct node *head2=NULL;
 int choice;
 int n,n2;
 printf("1.Push Stack\n2.Pop Stack\n3.Push Q\n4.Pop Q\n");
 printf("Select your choice:\n");
 scanf("%d",&choice);
 while(choice!=0)
 {
 switch(choice)
 {
 case 1:printf("Enter the no to push:\n");
        scanf("%d",&n);
		if(head==NULL)
		{
		head=(struct node * )malloc(sizeof(struct node));
		head->data=n;
		head->nextLink=NULL;
		}
		else
		pushstack((&head),n);
	break;
case 2:printf("The popped element is:%d\n",popstack());
	break;	
case 3:printf("Enter the element in the queue:");
       scanf("%d",&n2);
	   if(head2==NULL)
		{
		head2=(struct node * )malloc(sizeof(struct node));
		head2->data=n2;
		head2->nextLink=NULL;
		front=head2;
		}
		else
		pushq((&head2),n2);
	break;
case 4:printf("The popped element is:%d\n",popq());
	break;	
 }
 
 printf("Select your choice:\n");
 scanf("%d",&choice);
 }
 }
 
 