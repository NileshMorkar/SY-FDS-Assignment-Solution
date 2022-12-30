#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class Queue_LL
{
    private:
        Node *front,*rear;
    public:
        Queue_LL();
        void enQueue(int );
        int deQueue();
        bool isEmpty();
        int viewFront();
        int viewRear();
        void view();
        int count();
        ~Queue_LL();
};
void Queue_LL::view()
{
    if(isEmpty())
        cout<<"Queue Is Empty \n";
    else
    {
        Node *t=front;
        while (t)
        {
            cout<<t->data<<"  ";
            t=t->next;
        }
    }
}
int Queue_LL::count()
{
    int k=0;
    Node *t=front;
    while (t)
    {
        k++;
        t=t->next;
    }
    return k;
}
Queue_LL::~Queue_LL()
{
    while (front)
        deQueue();
}
int Queue_LL::viewFront()
{
    if(front)
        return front->data;
    else
        return -1;
}
int Queue_LL::viewRear()
{
    if(front)
        return rear->data;
    else
        return -1;
}
bool Queue_LL::isEmpty()
{
    return front==NULL;
}
int Queue_LL::deQueue()
{
    int k=-1;
    Node *t;
    if(isEmpty())
        cout<<"Queue Is Empty\n";
    else
    {
            
        k=front->data;
        t=front;
        front=front->next;
        delete t;
        if(front ==NULL)
            rear=NULL;
    }
    return k;
}
void Queue_LL::enQueue(int k)
{
    Node *n;
    n=new Node;
    n->data=k;
    n->next=NULL;
    if(front == nullptr)   
        front=n;
    else
        rear->next=n;
    rear=n;
}
Queue_LL::Queue_LL()
{
    front=rear=NULL;
}
int main()
{
    int k;
    Queue_LL Q1;
    while (1)
    {
        cout<<"\n0.Exit()\n";
        cout<<"1.EnQueue\n";
        cout<<"2.DeQueue\n";
        cout<<"3.View\n";
        cout<<"4.IsEmpty\n";
        cout<<"5.viewFront\n";
        cout<<"6.viewRear\n";
        cout<<"7.count\n";
        cout<<"\nEnter Your Choice ==>";
        cin>>k;
        switch (k)
        {
            case 0:exit(0);
            case 1:
                cout<<"\nEnter A Data ==> ";
                cin>>k;
                Q1.enQueue(k);
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
                cout<<"Front Value ==> "<<Q1.viewFront();
                break;
            case 6:
                cout<<"Rear Value ==> "<<Q1.viewRear();
                break;
            case 7:
                cout<<"Count ==> "<<Q1.count();
                break;
         
            default:
                cout<<"\nInvalid Choice\n";
            break;
        }
    }
    return 0;
}
