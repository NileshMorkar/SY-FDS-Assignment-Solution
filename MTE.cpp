#include<iostream>
#include<stdlib.h>
//#include<conio.h>
using namespace std;
class Node
{
    private:
        Node *start;
        int PRN;
        string name;
        Node *next;
        Node* createNode()
        {
            Node *n;
            n=new Node;
            fflush(stdin);
            cout<<"\nEnter PRN ==> ";
            cin>>n->PRN;
            cout<<"\nEnter Name ==> ";
            cin>>n->name;
            n->next=NULL;
            return n;
        }
    public:
        Node()
        {
            start=NULL;
        }
        void insert_At_start()
        {
            Node *temp;
            temp=createNode();
            temp->next=start;
            start=temp;
        }
        void viewList()
        {
            Node *t;
            if(start==NULL)
                cout<<"\nList Is Empty\n";
            else
            {
                t=start;
                while (t)
                {
                    cout<<"Name ==> "<<t->name<<"\tPRN ==> "<<t->PRN<<endl;
                    t=t->next;
                }
            }
        }
        void insertAt_last()
        {
            Node *t,*temp;
            temp=createNode();
            if(start == NULL)
                start=temp;
            else
            {
                t=start;
                while (t->next)
                {
                    t=t->next;
                }
                t->next=temp;
                temp->next=NULL;
            }
        }
        void Delete_FirstNode()
        {
            Node *t;
            if(start ==NULL)
                cout<<"\nList Is Empty\n";
            else
            {
                t=start;
                start =t->next;
                free (t); 
            }
        }
        void DeleteNode(int no)
        {
            Node *t=start,*temp;
            if(start==NULL)
                cout<<"\nList Is Empty\n";
            else if(t->next==NULL && t->PRN ==no)
                Delete_FirstNode();
            else
            {
                while (t->next->PRN != no && t->next->next !=NULL)
                {
                    t=t->next;
                }
                if(t->next->next == NULL && t->next->PRN ==no)
                    Delete_LastNode();
                else
                {
                    temp=t->next;
                    t->next=t->next->next;
                    free( temp);
                }
            }    
        }
        void Delete_LastNode()
        {
            Node *t;
            if(start ==NULL)
                cout<<"List Is Empty\n";
            else
            {
                t=start;
                while (t->next->next)
                {
                    t=t->next;
                }
                free( t->next);
                t->next=NULL;
            }
        }
        int count()
        {
            int count=0;
            Node *t;
            t=start;
            while (t)
            {
                t=t->next;
                count++;
            }
            return count;
        }
};
int main()
{
    int ch;
    Node n1;
    while (1)
    {
        //system("cls");
        cout<<"\n\n0.exit\n";
        cout<<"1.Insert Student data At Start\n";
        cout<<"2.Delete Data\n";
        cout<<"3.Count Number of Students\n";
        cout<<"4.View List\n";
        cout<<"5.Insert Data AT Last\n";
        cout<<"\n\nEnter Your Choice ==>";
        cin>>ch;
        switch (ch)
        {
            case 0:exit(0);
            break;
            case 1:
                n1.insert_At_start();
                break;
            case 2:
                cout<<"\n\nEnter PRN Number ==> ";
                cin>>ch;
                n1.DeleteNode(ch);
                break;
            case 3:
                cout<<"\n\nTotal Number Of Students ==> "<<n1.count();
                break;
            case 4:
                n1.viewList();
                break;
            case 5:
                n1.insertAt_last();
                break;
        default:
            break;
        }
        //getch();
    }
    
    return 0;
}
