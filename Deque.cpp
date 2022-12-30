#include<iostream>
#include<conio.h>
using namespace std;
struct Node
{
    Node *prev;
    int data;
    Node *next;
};
class Deque
{
    private:
        Node *front,*rear;
    public:
    Deque();
        void enQueueFront(int);
        void enQueueRear(int);
        int deQueueFront();
        int deQueueRear();
        int getFront();
        int getRear();
        bool isEmpty();
        void view();
        ~Deque();

};
void Deque::view()
{
    if(isEmpty())
        cout<<"Queue Is Empty\n";
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
Deque::~Deque()
{
    while (front)
        deQueueFront();
}
int Deque::deQueueRear()
{
    int k=-1;
    if(rear)
    {
        if(front == rear)
        {
            k=rear->data;
            delete rear;
            rear=front=nullptr;
        }
        else
        {
            Node *t;
            k=rear->data;
            t=rear->prev;
            t->next=nullptr;
            delete rear;
            rear=t;
        }
    }
    return k;
}
int Deque::deQueueFront()
{
    int k=-1;
    if(front)
    {
        if(front == rear)
        {
            k=front->data;
            delete front;
            rear=front=nullptr;
        }
        else
        {
            Node *t;
            k=front->data;
            t=front;
            front=front->next;
            delete t;
        }
    }
    return k;  
}
int Deque::getRear()
{
    return rear->data;
}
int Deque::getFront()
{
    if(front)
        return front->data;
    return -1;
}
bool Deque::isEmpty()
{
    return front==nullptr;
}
Deque::Deque()
{
    front=rear=nullptr;
}
void Deque::enQueueRear(int data)
{
    Node *n;
    n=new Node;
    n->data=data;
    n->next=n->prev=nullptr;
    
    if(front == nullptr)
        front=rear=n;
    else
    {
        n->prev=rear; 
        rear->next=n;
        rear=n;
    }
}
void Deque::enQueueFront(int data)
{
    Node *n;
    n=new Node;
    n->data=data;
    n->next=n->prev=nullptr;

    if(front == nullptr)
        front=rear=n;
    else
    {
        n->next=front;
        front->prev=n;
        front=n;
    }
}
int main()
{
    int k;
    Deque D1;
    while (1)
    {
        system("cls");
        cout<<"\n\n0.Exit()\n";
        cout<<"1.enQueueFront\n";
        cout<<"2.enQueueRear\n";
        cout<<"3.deQueueFront\n";
        cout<<"4.deQueueRear\n";
        cout<<"5.gerFront\n";
        cout<<"6.getRear\n";
        cout<<"7.isEmpty\n";
        cout<<"8.view\n";

        cout<<"Enter Your Choice ==> ";
        cin>>k;
        switch (k)
        {
            case 0:exit(0);
            case 1:
                cout<<"Enter A Number ==> ";
                cin>>k;
                D1.enQueueFront(k);
                break;
            case 2:
                cout<<"Enter A Number ==> ";
                cin>>k;
                D1.enQueueRear(k);
                break;
            case 3:
                if(D1.isEmpty())
                    cout<<"Queue Is Empty\n";
                else
                    cout<<"Deleted Element ==> "<<D1.deQueueFront();
                break;
            case 4:
                if(D1.isEmpty())
                    cout<<"Queue Is Empty\n";
                else
                    cout<<"Deleted Element ==> "<<D1.deQueueRear();
                break;
            case 5:
                if(D1.isEmpty())
                    cout<<"Queue Is Empty\n";
                else
                    cout<<"Front Value ==> "<<D1.getFront();
                break;
            case 6:
                if(D1.isEmpty())
                    cout<<"Queue Is Empty\n";
                else
                    cout<<"Rear Value ==> "<<D1.getRear();
                break;
            case 7:
                if(D1.isEmpty())
                    cout<<"Queue Is Empty\n";
                else
                    cout<<"Queue Is Not Empty \n";
                break;
            case 8:
                D1.view();
                break;
            default:
                break;
        }
        getch();
    }    
    return 0;
}