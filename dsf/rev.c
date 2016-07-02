#include<stdio.h>

struct node{

int data;
struct node * nextLink;
};

struct node * root=NULL;

void create(int n){

struct node * temp;
struct node *visit=root;
	while(visit->nextLink!=NULL){
		visit=visit->nextLink;
	}
	temp=(struct node *) malloc(sizeof(struct node));
	temp->data=n;
	temp->nextLink=NULL;
	visit->nextLink=temp;
}

void reverse(){

struct node * prev=root;
struct node * visit=root->nextLink;
struct node * next=visit->nextLink;
static int c=1;

		while(next !=NULL){
		
			if(c==1){
	
				prev->nextLink=NULL;
				visit->nextLink=prev;
				prev=visit;
				
				visit=next;
				next=visit->nextLink;
				c++;
			}
			else{
				
				visit->nextLink=prev;
				prev=visit;
				visit=next;
				next=visit->nextLink;
			}
			
		}
		visit->nextLink=prev;
		root=visit;
}

void display(){

struct node *visit=root;

	while(visit!=NULL){
	
		printf("%d \t",visit->data);
		visit=visit->nextLink;
	}
	printf("\n");

}

void main(){

int choice,n;
printf("1.Create List\n2.Reverse List\n");
printf("Enter your choice:");
scanf("%d",&choice);
while(choice!=0){

	switch(choice){
	
		case 1:
				printf("Enter the number:");
				scanf("%d",&n);
				if(root==NULL){
					root=(struct node *) malloc(sizeof(struct node));
					root->data=n;
					root->nextLink=NULL;
				}
				else{
				
					create(n);
				}
		break;
		case 2: 
				printf("The reverse list is:\n");
				reverse();
				display();
		break;
	}
	printf("Enter choice:");
	scanf("%d",&choice);

}


}