#include<iostream>
#include<conio.h>
using namespace std;
struct Node
{
    int data;
    int priority;
    Node *next;
};
class PQueue
{
    private:
        Node *start;
    public:
        PQueue(){start=NULL;}
        void enQueue(int ,int);
        int deQueue();
        bool isEmpty();
        int viewFrontE();
        int viewFrontP();
        int viewRearE();
        int viewRearP();
        void view();
        int count();
        ~PQueue();
};
int PQueue::viewFrontE()
{
    if(start)
        return start->data;
    return -1;
}
int PQueue::viewFrontP()
{
    if(start)
        return start->priority;
    return -1;
}
int PQueue::viewRearE()
{
    if(start)
    {
        Node *t=start;
        while (t->next)
            t=t->next;
        return t->data;
    }
}
int PQueue::viewRearP()
{
    if(start)
    {
        Node *t=start;
        while (t->next)
            t=t->next;
        return t->priority;
    }
}
bool PQueue::isEmpty()
{
    return start==NULL;
}
PQueue::~PQueue()
{
    Node *t;
    while (start)
    {
        t=start;
        start=start->next;
        delete t;
    }
}
void PQueue::view()
{
    Node *t=start;
    while (t)
    {
        cout<<"Priority ==> "<<t->priority<<"\tData ==> "<<t->data<<endl;
        t=t->next;
    }
}
int PQueue::count()
{
    int k=0;
    Node *t=start;
    while (t)
    {
        k++;
        t=t->next;
    }
    return k;
}
int PQueue::deQueue()
{
    if(start)
    {
        int k=start->data;
        Node *t=start;
        start=start->next;
        delete t;
        return k;    
    }
    return -1;
}
void PQueue::enQueue(int data,int priority)
{
    Node *n=new Node;
    n->data=data;
    n->priority=priority;
    n->next=NULL;   
    if(start == NULL)
        start=n;
    else if(start->next == nullptr || start->priority < priority)
    {
        if(start ->priority > priority)
            start->next=n;
        else
        {
            n->next=start;
            start=n;    
        }
    }
    else
    {
        Node *t=start;
        while (t->next && t->next->priority > priority)
            t=t->next;
        n->next=t->next;
        t->next=n;
    }   
}
int main()
{
    int k,p;
    PQueue Q1;
    while (1)
    {
        cout<<"\n0.Exit()\n";
        cout<<"1.EnQueue\n";
        cout<<"2.DeQueue\n";
        cout<<"3.View\n";
        cout<<"4.IsEmpty\n";
        cout<<"5.viewFrontE\n";
        cout<<"6.viewRearE\n";
        cout<<"7.viewFrontP\n";
        cout<<"8.viewRearP\n";
        cout<<"9.count\n";
        cout<<"\nEnter Your Choice ==>";
        cin>>k;
        switch (k)
        {
            case 0:exit(0);
            case 1:
                cout<<"\nEnter A Data ==> ";
                cin>>k;
                cout<<"\nEnter A Priority ==> ";
                cin>>p;
                Q1.enQueue(k,p);
                break;
            case 2:
                cout<<Q1.deQueue();
                break;
            case 3:
                Q1.view();
                break;
            case 4:
                if(Q1.isEmpty())
                    cout<<"Queue IS Empty\n";
                else
                    cout<<"Queue IS NOT Empty\n";
                break;
            case 5:
                cout<<"Front DATA Value ==> "<<Q1.viewFrontE();
                break;
            case 6:
                cout<<"Rear DATA Value ==> "<<Q1.viewRearE();
                break;
            case 7:
                cout<<"Front Priority Value ==> "<<Q1.viewFrontP();
                break;
            case 8:
                cout<<"Rear Priority Value ==> "<<Q1.viewRearP();
                break;
            case 9:
                cout<<"Count ==> "<<Q1.count();
                break;

            default:
                cout<<"\nInvalid Choice\n";
            break;
        }
        getch();
    }
    return 0;
}
