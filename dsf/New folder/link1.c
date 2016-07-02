 #include<stdio.h>
 //#include<conio.h>
 struct node
 {
 int data;
 struct node * nextLink;
 struct node * prevLink;
 };

 struct node * add(int n,struct node * head)
 {
    struct node * visitptr;
    struct node * temptr;
   if(head==NULL)
    {
     head=(struct node * )malloc(sizeof(struct node));
     head->data=n;
     head->nextLink=NULL;
    }
  else
    {
      visitptr=head;
      while(visitptr->nextLink!=NULL)
       {
      visitptr=visitptr->nextLink;
       }
       temptr=(struct node * )malloc(sizeof(struct node));
       temptr->data=n;
       temptr->nextLink=NULL;
       visitptr->nextLink=temptr;

    }
 return head;
 }

 struct node * copy(struct node * head1,struct node * head2)
 {

  struct node * visitptr1;
  visitptr1=head1;
  while(visitptr1->nextLink!=NULL)
  {
 int d=visitptr1->data;
 head2 = add(d,head2);
 visitptr1=visitptr1->nextLink;
 }
 if(visitptr1->nextLink==NULL)
 {
 int d1=visitptr1->data;
 head2=add(d1,head2);
 }
 return head2;
 }
 
 struct node * concat(struct node *head1,struct node *head2)
 {
 struct  node *visitptr;
 visitptr=head1;
 while(visitptr->nextLink!=NULL)
 {
 visitptr=visitptr->nextLink;
 }
 visitptr->nextLink=head2;
 
 return head1;
 }
 
 struct node * reverse(struct node *head)
 {
 struct node *visitptr,*temptr;
 int c=0;
 visitptr=head;
 while(visitptr!=NULL)
 {
 c++;
 if(c==1)
 {
 visitptr->prevLink=NULL;
 temptr=visitptr;
 visitptr=visitptr->nextLink;
 }
 else
 {
 visitptr->prevLink=temptr;
 temptr=visitptr;
 visitptr=visitptr->nextLink;
 }
 }
 return temptr;
 }
 

 
 


void display(struct node *head)
{
  struct node *visitptr;
  visitptr=head;
  while(visitptr!=NULL)
   {
   printf("%d\n",visitptr->data);
   visitptr=visitptr->nextLink;
   }
 }
 
 void displayrev(struct node *head)
{
  struct node *visitptr;
  visitptr=head;
  while(visitptr != NULL)
   {
   printf("%d\n",visitptr->data);
   visitptr=visitptr->prevLink;
   }
 }
 
 void split(struct node **head)
 {
 int c=0,d;
 struct node *visit,*split1=NULL,*split2=NULL;
 visit=*head;
 while(visit!=NULL)
 {
	c++;
	if((c%2)!=0)
	{
	  d=visit->data;
	  split1=add(d,split1);
	  visit=visit->nextLink;
	}
    else
	{
	d=visit->data;
	split2=add(d,split2);
	visit=visit->nextLink;
	}
    	
 }
 printf("The splitted link1 is:\n");
 display(split1);
 printf("The splitted link2 is:\n");
 display(split2);
 
 }
 



 void main()
 {
 struct node * head1,* head2,*con,*rev;
 int choice,n;
 //clrscr();
 head1 = NULL;
 head2 = NULL;
 con=NULL;
 rev=NULL;
 
 
 printf("1.Add\n2.Copy\n3.Display Head\n4.Display Copy\n5.Concatenation\n6.Display Concat\n7.Reverse\n8.Display Reverse\n9.Display Split\n");
 printf("Select your choice:\n");
 scanf("%d",&choice);

 while(choice!=0)
 {
    switch(choice)
    {
    case 1:printf("Enter number to add:\n");
	scanf("%d",&n);
	head1 = add(n,head1);
	break;
   case 2:head2=copy(head1,head2);
	printf("Copied Successfully\n");
	break;
   case 3:display(head1);
	break;
   case 4:display(head2);
	break;
   case 5:con=concat(head1,head2);
         printf("Concatenated Successfully\n");
    break;
   case 6:display(con);
    break;
   case 7:rev=reverse(head1);
          printf("Reversed Successfully\n");
    break;
   case 8:displayrev(rev);
    break;
   case 9:split(&head1);
          printf("Splitted Successfully\n");
		  
   break;
   
 }
 printf("Select your choice:\n");
 scanf("%d",&choice);
 }

 }

