#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
 int info;
 struct node *link;
};

 struct node* delbeg(struct node *START);
struct node* createnode()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	return(temp);
}
// INSERTING AT BEGGINING
struct node * addatbeg(struct node *START,int value)
{
	struct node *p,*q;
	p=createnode();

	p->info=value;
	p->link=NULL;
	if(START==NULL)
	{
	START=p;
	p->link=START;

	}
	else
	{
		q=START;
		p->link=START;
	       //	START=p;
		while(q->link!=START)
			q=q->link;
		q->link=p;
		START=p;

	}
	return(START);
}
// INSERTING AT END
struct node* addatend(struct node *START,int value)
{
	struct node *t,*p;
	t=createnode();
	t->info=value;
	t->link=NULL;
	if(START==NULL)
	{
		START=t;
		t->link=START;
	}
	else
	{
	p=START;
	do
	{
		p=p->link;
	}while(p->link!=START);
	t->link=p->link;
	p->link=t;


	}
	return(START);
}
// SIZE OF LINK LIST
int sizecount(struct node *START)
{
	if(START==NULL)
	return(0);
	else
	{
		struct node *p;
		int count=0;
		p=START;
		do
		{
			count++;
			p=p->link;
		}while(p!=START);
		return(count);
	}
}
//ADD AT POSITION
struct node* addatpos(struct node *START,int position,int value)
{
	if(START==NULL)
	printf("List is empty");
	else
	{
		int p;
		p=sizecount(START);
		if(position<0 || position>p-1)
		 printf("Invalid position");
		 else
		 {
		 	if(position==0)
		 	START=addatbeg(START,value);
		 	else
		 	{
		 		int i;
		 		struct node *temp,*p;
		 		temp=createnode();
		 		temp->info=value;
				 temp->link=NULL;
				 p=START;
		 		for(i=1;i<position;i++)
		 		{
		 			p=p->link;
				 }
				 temp->link=p->link;
				 p->link=temp;
			 }
		 }
	}
	return(START);
}
// DELETE AT END
struct node* delatend(struct node *START)
{
	if(START==NULL)
		printf("List is empty");
	else
	{
		struct node *last,*seclast;
		if(START->link==START)
		    START=delbeg(START);
		else
		{
		last=START;
		do
		{
			seclast=last;
			last=last->link;
		}while(last->link!=START);
		seclast->link=START;
		last->link=NULL;
		free(last);
			
		}
	}
	return(START);
}
 // TRAVERSE
 void traverse(struct node *START)
 {
   if(START==NULL)
 {
	printf(" \nList is empty");
 }

 else{

	struct node *a;
	a=START;
	do
	{
		printf("%d->",a->info);
		a=a->link;
	 }while(a!=START);

 }
 getch();
}
 // DELETE BY VALUE
 struct node* delbyval(struct node *START,int value)
 {
	struct node *last,*secondlast;
	if(START==NULL)
	{
		printf("List is empty");
	 }
	 else
    {
	if(START->link==START)
	{
		if(START->info==value)
		{
		   START=delbeg(START);
			}
			else
			printf("Node with given value does not exist");
		}
		else
		{   if(START->info==value)
		{
			START=delbeg(START);
		}
		else{

			last=START;
			secondlast=START;
			do
			{

				if(last->info==value)
				{
					secondlast->link=last->link;
					last->link=NULL;
					free(last);
					break;
				}
				secondlast=last;
				last=last->link;
			}while(last!=START);
		}
		}
	}

	 return(START);

 }

 // DELETION OF BEGGINING
 struct node* delbeg(struct node *START)
 {
	struct node *p,*q;
	if(START==NULL)
	{
		printf("List is empty");
	 }
	 else
	 {

	    if(START->link==START)
	    {

		p=START;
		START=NULL;
		free(p);
		}
		else
		{
			p=START;

			q=START->link;
			while(q->link!=START)
				q=q->link;
			START=START->link;
			q->link=START;
			free(p);
		}
	 }
	 return(START);
 }


 int menu()
 {
 	printf("\n1. Insert at Beggining");
 	printf("\n2. Insert at End");
 	printf("\n3. Insert at Position");
 	printf("\n4. Delete by value");
 	printf("\n5. Delete at beggining");
 	printf("\n6. Delete at end");
 	printf("\n7. Traverse");
 	printf("\n8. Exit");
 	
 	int ch;
 	printf("\n Enter your choice : ");
 	scanf("%d",&ch);
 	return(ch);
 }
 
 main()
 {
 	struct node *START=NULL;
 	int v,pos;
 	 while(1)
 	 {
 	 	system("cls");
 	 	switch(menu())
 	 	{
 	 		case 1: printf(" \n Enter the value : ");
 	 		scanf("%d",&v);
 	 		START=addatbeg(START,v);
 	 		traverse(START);
 	 		break;
 	 		
 	 		case 2: printf(" \n Enter the value : ");
 	 		scanf("%d",&v);
 	 		START=addatend(START,v);
 	 		traverse(START);
 	 		break;
 	 		case 3: printf("\n Enter the Position : ");
 	 		        scanf("%d",&pos);
 	 		        printf("\n Enter the value : ");
 	 		        scanf("%d",&v);
 	 		        START=addatpos(START,pos,v);
 	 		        printf("\n");
 	 		        traverse(START);
 	 		        break;
 	 		case 4:  printf(" \n Enter the value you want to delete : ");
 	 		scanf("%d",&v);
 	 		START=delbyval(START,v);
 	 		traverse(START);
 	 		break;
 	 		
 	 		case 5: START=delbeg(START);
 	 		        traverse(START);
 	 		        break;
 	 		case 6: START=delatend(START);
			        traverse(START);
					break;        
 	 		case 7: traverse(START);
 	 		break;
 	 		
 	 		case 8: exit(1);
 	 		break;
 	 		
 	 		default : printf("Invalid Choice");
 	 		break;
		  }
	  }
 	
 }
