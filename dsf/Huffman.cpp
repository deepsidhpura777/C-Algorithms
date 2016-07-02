#include<iostream>
using namespace std;
struct node
{
string code;
string character;
int frequency;
struct node * left;
struct node * right;
};
struct node * queue[20];
int front=0,rear=0;
bool flag=false;


void inorder(struct node* root)
{
	if(root == NULL)	return;
	inorder(root->left);
	cout<<root->character;
	inorder(root->right);
}

void create() //after calling create in the main,call sort
{
struct node * temp = new node();
cout<<"Enter the character:"<<endl;
cin>>temp->character;
cout<<"Enter the frequency:"<<endl;
cin>>temp->frequency;
temp->left=NULL;
temp->right=NULL;
queue[rear++]=temp;
}

void sort()
{
int j,key,i;
struct node * temp;
	for(j=front+1;j<rear;j++)
	{
		key=queue[j]->frequency;
		temp=queue[j];
		i=j-1;
		while((queue[i]->frequency) > key && i>=0)
		{
			queue[i+1]=queue[i];
			i--;
		}
		queue[i+1]=temp;
	}
	
	
}


void tree()
{
	while(front!=rear-1)
	{
		struct node * t1=queue[front++];
		struct node * t2=queue[front++];
		struct node * temp= new node();
		temp->frequency=(t1->frequency)+(t2->frequency);
		temp->character=(t1->character)+(t2->character);
		temp->left=t1;
		temp->right=t2;
		queue[rear++]=temp;
		sort();
	}
}

void createCode(struct node * root) //Pass the queue[front] initially as the root node 
{
struct node * temp= root;
	if(temp->left != NULL)
	{
	 //cout<<"Left"<<endl;
	 temp=temp->left;
	 temp->code="0";
	 createCode(temp);
	}
	temp = root;
	if(temp->right != NULL)
	{
	 //cout<<"Right:"<<endl;
	 temp=temp->right;
	 temp->code="1";
	 createCode(temp);
	}
	
	
	
}

void displayCode(struct node * root)
{
struct node * temp=root;
string c,d;
	if(temp->left!=NULL)
	{
		c+=temp->code;
		temp=temp->left;
		c+=temp->code;
		temp->code=c;
		displayCode(temp);
		temp=root;
	}
	
	/*else
	{
	cout<<"Character:"<<temp->character<<endl;
	cout<<"Code:"<<temp->code<<endl;
	}*/
	
	
	
	
	
	if(temp->right != NULL)
	{
		d+=temp->code;
		temp=temp->right;
		d+=temp->code;
		temp->code=d;
		displayCode(temp);
		temp=root;
	   
	}
	
    if(temp->left==NULL && temp->right==NULL)
	{
	cout<<"Character:"<<temp->character<<endl;
	cout<<"Code:"<<(temp->code).substr(1)<<endl;
	}
	
	
	
}

int main()
{
struct node * root;
int c;
for(int i=0;i<20;i++)
{
queue[i]=NULL;
}
cout<<"To Enter the data for the elements, press 1 and 0 to stop"<<endl;
cin>>c;
while(c!=0)
{
create();
cout<<"Press 1 to continue"<<endl;
cin>>c;
}
sort();
tree();
root=queue[front];
root->code="0";

createCode(root);

displayCode(root);


return 0;
}

