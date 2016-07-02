#include<stdio.h>
#include<conio.h>
#define FALSE 0
#define TRUE 1

struct node
{
int vertex;
struct node * nextLink;
};

struct node * arrayList[20];
int visited[20];
int queue[20];
int front=0,rear=0;
int counter=0;

void create(int vertex1,int vertex2)
{
struct node * first, * second, * temp1=NULL, * temp2=NULL;
first=arrayList[vertex1]; // Holds the addresss of the respective vertices.
second=arrayList[vertex2];

temp1=(struct node * )malloc(sizeof(struct node));
temp1->vertex=vertex1;
temp1->nextLink=NULL;

temp2=(struct node * )malloc(sizeof(struct node));
temp2->vertex=vertex2;
temp2->nextLink=NULL;

if(first==NULL)
{
arrayList[vertex1]=temp2;
}
else
{
	while(first->nextLink!=NULL)
	first=first->nextLink;
first->nextLink=temp2;
}

if(second==NULL)
{
arrayList[vertex2]=temp1;
}
else
{
	while(second->nextLink!=NULL)
	second=second->nextLink;
second->nextLink=temp1;
}
}

void bfs(int startingvertex) //first print adjacent nodes of starting vertex,then start adding them in a queue to repeat the same process for them.
{
queue[rear++]=startingvertex;
	while(front<counter) //counter counts the no of vertices added
	{
		if(visited[startingvertex]==FALSE)
		{
		printf("%d\n",queue[front++]);
		visited[startingvertex]=TRUE;
		}

struct node * first=arrayList[startingvertex];
		while(first!=NULL)
		{
			if(visited[first->vertex]==FALSE)
			{
			queue[rear++]=first->vertex;
			}
		first=first->nextLink;
		}
	//int f=front+1;
	startingvertex=queue[front];
	//printf("Front Value:%d\n",front);
	}
}

void dfs(int startingvertex) //No queue required to be maintained
{
	if(visited[startingvertex]==FALSE)
	{
		printf("%d\n",startingvertex);
		visited[startingvertex]=TRUE;
	}

struct node * first=arrayList[startingvertex]; //storing the address of the starting node from arrayList in first var.
	while(first!=NULL)
	{
		if(visited[first->vertex]==FALSE)
			dfs(first->vertex);
		else
			first=first->nextLink;
	}


}

void main()
{
int choice,ch;
int v1,v2,startingvertex;
int i;
for(i=0;i<20;i++)
			{		
				//visited[i]=FALSE;
				arrayList[i]=NULL;
			}

printf("1.Create\n2.BFS\n3.DFS\n");
scanf("%d",&choice);
while(choice!=0)
{
switch(choice)
{
case 1:
       
	   printf("Enter the 2 vertices with the edge:\n");
	   scanf("%d",&v1);
	   scanf("%d",&v2);
	   create(v1,v2);
	   printf("Added Successfully in the Graph\n");
       counter++;

	break;

case 2:		for(i=0;i<20;i++)
			{		
				visited[i]=FALSE;
				//arrayList[i]=NULL;
			}
		printf("Enter the starting vertex:\n");
       scanf("%d",&startingvertex);
	   bfs(startingvertex);
	break;

case 3:
        for(i=0;i<20;i++)
		{
			visited[i]=FALSE;
			//arrayList[i]=NULL;
		}
	   printf("Enter the starting vertex:\n");
       scanf("%d",&startingvertex);
	   dfs(startingvertex);
	break;



}
printf("Select your choice\n");
scanf("%d",&choice);
}

}

