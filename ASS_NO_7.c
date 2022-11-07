/*Department of Information Technology has a students club named Pinnacle Club. Students of the
Second, third and final year of the department can be granted membership on request. Similarly,
one may cancel the membership of the club. The first node is reserved for the president of the club
and the last node is reserved for the secretary of the club. Write C program to maintain club
members information using a singly linked list. Store student PRN and Name. Write functions to
a) Add and delete the members as well as the president or even secretary.
b) Compute the total number of members of the club
c) Display members of the club
d) Display list in reverse order using recursion
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node 
{
    char name[20];
    int prn;
    struct Node *next;
    struct Node *prev;
};
void insertSecretary(struct Node **s);
void insertPresident(struct Node**);
struct Node* createNode()
{   
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter Name ==> ");
    fflush(stdin);
    scanf("%s",n->name);
    printf("Enter PRN  Number ==> ");
    fflush(stdin);
    scanf("%d",&n->prn);
    n->next=n->prev=NULL;
    return n;
}
void insertNode(struct Node **s)
{
    struct Node *temp,*t;
    if(*s==NULL)
    {
        insertPresident(s);
        insertSecretary(s);
    }
    else 
    {
        printf("\n------ For Member --------\n");
        temp=createNode();
        t=*s;
        while (t->next->next)
        {
            t=t->next;
        }
        temp->prev=t;
        temp->next=t->next;
        t->next->prev=temp;
        t->next=temp;
    }       
}
void viewList(struct Node **s)
{
    struct Node *t;
    if(*s==NULL)
        printf("\nList Is Empty\n");
    else
    {
        t=*s;
        printf("\n\n");
        while (t)
        {
            printf("PRN : %d\tName : %s\n",t->prn,t->name);
            t=t->next;
        }
        printf("\n\n");
    }
}
void insertPresident(struct Node **s)
{
    struct Node *t;
    printf("\n ------For President ------\n");
    t=createNode();
    
    if(*s==NULL)
    {
        *s=t;
    }
    else
    {
        t->next=(*s)->next;
        free(*s);
        *s=t;
    }
}
void insertSecretary(struct Node **s)
{
    struct Node *temp,*t=*s;
    printf("\n -----For Secretary ------\n");
    temp=createNode();
    if((*s)->next==NULL)
    {
        (*s)->next=temp;
        temp->prev=*s; 
    }
    else
    {
        while (t->next->next)
        {
            t=t->next;
        }
        free(t->next);
        t->next=temp;
        temp->prev=t;
    }
}
int totalMembers(struct Node **s)
{
    int count=0;
    struct Node *t=*s;
    while (t->next)
    {
        count++;
        t=t->next;
    }
    return count-1;
}
void viewMembers(struct Node **s)
{
    struct Node *t;
    if(*s==NULL)
        printf("\nClub Is Empty\n");
    else if((*s)->next->next==NULL)
    {
        printf("\nNo Members\n");
    }
    else 
    {
        t=(*s)->next;
        while (t->next)
        {
            printf("PRN : %d\tName : %s\n",t->prn,t->name);
            t=t->next;    
        }
        
    }
}
int main()
{
    int ch;
    struct Node *start=NULL;
    while (1)
    {
        printf("\n\n0.Exit\n");
        printf("1.View List\n");
        printf("2.Insert Member\n");
        printf("3.Change OR Insert President\n");
        printf("4.Change OR Insert Secretarry\n");
        printf("5.Count Total Members of Club\n");
        printf("\nEnter Your Choice ==>");
        scanf("%d",&ch);
        switch (ch)
        {
            case 0:exit(0);
            case 2:
                insertNode(&start);
                break;
            case 1:
                viewList(&start);
                break;
            case 3:
                insertPresident(&start);
                break;
            case 4:
                insertSecretary(&start);
                break;
            case 5:
                printf("\nTotal Members ==> %d\n\n",totalMembers(&start));
                break;
           default:
            break;
        }
    }
    
    return 0;
}
