// 1.SLL: Store the list of records in a singly linked list. Print all entries in the linked list.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

typedef struct node 
{
    int id;
    char fname[SIZE];
    char lname[SIZE];
    char gender[SIZE];
    char occupation[SIZE];
    int age;
    struct node *next;
} club_member;

club_member *head = NULL;

void create_list(club_member **head, club_member m);
void display(club_member *head);
void release_memory(club_member **head);

int main() 
{
    FILE *fp;
    char buf1[SIZE], buf2[SIZE], buf3[SIZE], buf4[SIZE], buf5[SIZE];
    
    fp = fopen("Club_Membership_2020.txt", "r");
    if(fp == NULL) 
    {
        printf("Error in opening file\n");
        exit(1);
    }

    int i = 0;
    while (i < 16) 
    {
        club_member m;
        if(i == 0) 
        {
            fscanf(fp, "%s %s %s %s %s", buf1, buf2, buf3, buf4, buf5);
            printf("%s\t %s\t\t\t %s\t %s\t %s\n", buf1, buf2, buf3, buf4, buf5);
        }
        else 
        {
            fscanf(fp, "%d %s %s %s %s %d", &m.id, m.fname, m.lname, m.gender, m.occupation, &m.age);
            create_list(&head, m);
        }
        i++;
    }
    display(head);
    release_memory(&head);
    fclose(fp);
    return 0;
}

void create_list(club_member **head, club_member m) 
{
    club_member *newnode = (club_member *)malloc(sizeof(club_member));
    if(newnode == NULL) 
    {
        printf("Cannot allocate memory\n");
        exit(1);
    }
    *newnode = m;
    newnode->next = NULL;
    if(*head == NULL) 
    {
        *head = newnode;
    }
    else 
    {
        club_member *temp = *head;
        while(temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display(club_member *head) 
{
    if(head == NULL) 
    {
        printf("No data in the file\n");
    }
    else 
    {
        club_member *temp = head;
        while(temp != NULL) 
        {
            printf("%d\t%s %s\t\t%s\t%s\t\t%d\n", temp->id, temp->fname,temp->lname, temp->gender, temp->occupation, temp->age);
            temp = temp->next; 
        }
    }
}

void release_memory(club_member **head) 
{
    club_member *temp = *head;
    while(temp != NULL) 
    {
        club_member *temp1 = temp;
        temp = temp->next;
        free(temp1);
    }
    *head = NULL;
}
