#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node* creatNode()
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter a Data ==> ");
    scanf("%d",&t->data);
    t->next=NULL;    
    return t;
}
void insertNode(struct Node **S)
{
    struct Node *temp,*t;
    temp=creatNode();
    if(*S==NULL)
        *S=temp;
    else
    {
        t=*S;
        while (t->next)
        {
            t=t->next;
        }
        t->next=temp;
    }
}
void viewList(struct Node **S)
{
    struct Node *t;
    if(*S==NULL)
        printf("\nList Is Empty\n");
    else
    {
        t=*S;
        while(t)
        {
            printf("%d ",t->data);
            t=t->next;
        }
    }
}
void delete_LastNode(struct Node **S)
{
    struct Node *t;
    t=*S;
    while ((t->next)->next)
    {
        t=t->next;
    }
    free(t->next);
    t->next=NULL;
}
void delete_firstNode(struct Node **S)
{
    struct Node *t;
    if(*S==NULL)
    {    
        printf("\nList Is Empty\n");
        getch();
    }
    else 
    {
        t=*S;
        *S=t->next;
        free (t);
    }
}
struct Node* Reverse_linkedList(struct Node **S)
{   
    struct Node *t1,*t2;
    t1=t2=NULL;
    while (*S)
    {
        t2=(*S)->next;
        (*S)->next=t1;
        t1=*S;
        *S=t2;
    }
    return t1;  
}
int main()
{  
    struct Node *Start;
    int i;
    Start=NULL;
    system("cls");
    while (1)
    {
        printf("1.View List\n");
        printf("2.Insert at LAST\n");
        printf("3.Insert at First\n");
        printf("4.Insert at AnY Position\n");
        printf("5.Delete LAST Node\n");
        printf("6.Delete First Node\n");
        printf("7.Delete AnY Node\n");
        printf("8.Reverse Linked List\n");

        printf("\nEnter Your Choice ==> ");
        scanf("%d",&i);
        switch (i)
        {
            case 1:
                viewList(&Start);
                getch();
                break;
            case 2:
                insertNode(&Start);
                break;
            case 5:
                delete_LastNode(&Start);
                break;
            case 6:
                delete_firstNode(&Start);
                break;
            case 8:
                Start=Reverse_linkedList(&Start);
                viewList(&Start);
                getch();
                break;
            default:
                printf("\nInvalid Input\n");
                break;
        }
        system("cls");
    }
    
    return 0;
}
