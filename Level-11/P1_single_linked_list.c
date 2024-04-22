/* 1.Program to implement Single linked list with functions insert_at_front, insert_at_rear, 
insert_at_position, delete_at_front, delete_at_rear, delete_at_position */


#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;           
    struct node *next; 
}*head;


void createList(int n);
void insertNodeAtBeginning(int data);
void insertNodeAtEnd(int data);
void insertNodeAtPosition(int data,int position);
void deleteNodeAtBeginning();
void deleteNodeAtEnd();
void deleteNodeAtPosition(int data,int position);
void displayList();


int main()
{
	int choice,data,n,position;
	printf("Enter the total number of nodes: ");
	scanf("%d",&n);
	
	createList(n);
	
	do
	{
		printf("\n1.Display List \n");
		printf("2.Insert Node at Beginning\n");
		printf("3.Insert Node at End\n");
		printf("4.Insert Node at position\n");
		printf("5.Delete Node at Beginning\n");
		printf("6.Delete Node at End\n");
		printf("7.Delete Node at position\n");
		printf("0.Exit\n");
		
		printf("Enter your choice :");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 0: printf("Exiting the program\n");
				    break;
			case 1: printf("\nData in the list\n");
				    displayList();
				    break;
			case 2: printf("Enter the data to insert at the beginning:");
				    scanf("%d",&data);
				    insertNodeAtBeginning(data);
				    break;
			case 3: printf("Enter the data to insert at the end:");
				    scanf("%d",&data);
				    insertNodeAtEnd(data);
				    break;
			case 4: printf("\nEnter data to insert:");
    				scanf("%d",&data);
    				printf("Enter the position to insert:");
    				scanf("%d",&position);
    				insertNodeAtPosition(data,position);
    				break;
			case 5: deleteNodeAtBeginning();
				    break;
			case 6: deleteNodeAtEnd();
				    break;
			case 7: printf("Enter data to delete:");
			        scanf("%d",&data);
			        printf("Enter the position to delete:");
			        scanf("%d",&position);
			        deleteNodeAtPosition(data,position);
		            break;
    			default : printf("Invalid choice. Please enter a valid option.\n");
    		}
    	}while(choice!=0);
    return 0;
}
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head->data = data; 
        head->next = NULL; 
        temp = head;
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                newNode->data = data; 
                newNode->next = NULL; 
                temp->next = newNode; 
                temp = temp->next; 
            }
        }
        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
void insertNodeAtBeginning(int data)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = head; 
        head = newNode;          
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

void insertNodeAtEnd(int data)
{
	struct node *newNode,*temp;
	newNode=(struct node*)malloc(sizeof(struct node));
	if(newNode==NULL)
	{
		printf("Unable to allocate memory.");
		return;
	}
	newNode->data=data;
	newNode->next=NULL;
	
	if(head==NULL)
	{
		head=newNode;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newNode;
	}
	printf("Data inserted at the end successfully.\n");
}

void insertNodeAtPosition(int data,int position)
{
	struct node *temp,*newNode;
	int i;
	
	newNode=(struct node*)malloc(sizeof(struct node));
	if(newNode==NULL)
	{
		printf("Unable to allocate memory.");
		return;
	}
	newNode->data=data;
	newNode->next=NULL;
	
	if(position==1)
	{
		newNode->next=head;
		head=newNode;
		printf("Data inserted at position %d successfully.\n",position);
	}
	else
	{
		temp=head;
		for(i=1;i<position-1 && temp!=NULL; i++)
		{
			temp=temp->next;
		}
		
		if(temp==NULL)
		{
			printf("Invalid position.\n");
		}
		else
		{
			newNode->next = temp->next;
			temp->next=newNode;
			printf("Data inserted at position %d successfully.\n",position);
		}
	}
}
void deleteNodeAtBeginning()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty, cannot delete.\n");
		return;
	}
	temp=head;
	head=head->next;
	free(temp);
	
	printf("Node deleted from the beginning successfully.\n");
}

void deleteNodeAtEnd()
{
	struct node *temp,*prev;
	if(head==NULL)
	{
		printf("List is empty, cannot delete.\n");
		return;
	}
	temp=head;
	prev=NULL;
	
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	
	if(prev==NULL)
	{
		free(head); 
		head=NULL;
	}
	else
	{
		prev->next=NULL;
		free(temp);
	}
	printf("Node deleted from the end successfully.\n");
}

void displayList()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); 
            temp = temp->next;                 
        }
    }
}

void deleteNodeAtPosition(int data,int position)
{
    struct node *temp, *prev;
    int count = 1;
    if(head == NULL)
    {
        printf("List is empty.");
        return;
    }
    temp = head;
    if(position == 1)
    {
        head = temp->next;
        free(temp);
        printf("Node deleted from position %d successfully.\n", position);
        return;
    }
    while(temp != NULL && count < position)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if(temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted from position %d successfully.\n", position);
}
