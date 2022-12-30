#include<iostream>
#include<conio.h>
using namespace std;
class Queue
{
    private:
        int front,rear;
        int capacity;
        int *array;
    public:
        Queue(int);
        bool isEmpty();
        bool isFull();
        int deQueue();
        void enQueue(int);
        int viewFront();
        int viewRear();
        int count();
        void viewQueue();
        ~Queue();
            
};
void Queue::viewQueue()
{   
    if(isEmpty())
        cout<<"Queue Is Empty\n";
    else
    {
        int i;
        for (i=front ;i !=rear ;i=(i+1)%capacity)
            cout<<array[i]<<"  ";
        cout<<array[i]<<"  ";
    }           
}
int Queue::count()
{
    if(isEmpty())
        return 0;
    else if(front<=rear)
        return rear-front+1;
    else
        return capacity-(front-rear-1);
}
int Queue::viewFront()
{
    if(isEmpty())
        return array[front];
    else
        return -1;
}
int Queue::viewRear()
{
    if(isEmpty())
        return array[rear];
    else
        return -1;
}
int Queue::deQueue()
{
    int k=-1;
    if(isEmpty())
        cout<<"Queue Is Empty \n";
    else
    {
        k=array[front];
        if(rear == front)
            rear = front = -1;
        else
            front=(front+1)%capacity;
    }
    return k;
}
void Queue::enQueue(int k)
{
    if(isFull())
        cout<<"Queue Is Full \n";
    else
    {
        rear =(rear+1)%capacity;
        if(front == -1)
            front=rear;
        array[rear]=k;
    }
}
bool Queue::isFull()
{
    return front==(rear+1)%capacity;    
}
bool Queue::isEmpty()
{
    return rear==-1;
}
Queue::~Queue()
{
    delete []array;   
}
Queue::Queue(int cap)
{
    front=rear=-1;
    capacity=cap;
    array=new int[capacity];
}
int main()
{
    Queue Q1(5);
    int k;
    while (1)
    {
        system("cls");
        cout<<"\n\n0.Exit() \n";
        cout<<"1.Enqueue \n";
        cout<<"2.Dequeqe \n";
        cout<<"3.isEmpty \n";
        cout<<"4.isFull \n";
        cout<<"5.viewFront \n";
        cout<<"6.viewRear \n";
        cout<<"7.ViewQueue \n";
        cout<<"8.count \n";
        cout<<"\n\nEnter Your Choice ==> ";
        cin>>k;

        switch (k)
        {
            case 0:exit(0);
            case 1:
                if(Q1.isFull())
                    cout<<"Queue Is Full \n";
                else
                {
                    cout<<"Enter Your Data ==> ";
                    cin>>k;
                    Q1.enQueue(k);
                }
                break;
            case 2:
                if(Q1.isEmpty())
                    cout<<"Queue Is Empty \n";
                else
                    cout<<"Deleted Data ==> "<<Q1.deQueue();
                break;
            case 3:
                if(Q1.isEmpty())
                    cout<<"Queue Is Empty \n";
                else
                    cout<<"Queue Is Not Empty \n";
                break;
            case 4:
                if(Q1.isFull())
                    cout<<"Queue Is Full \n";
                else
                    cout<<"Queue Is Not Full \n";
                break;
            case 5:
                cout<<"Front Value ==> "<<Q1.viewFront();
                break;
            case 6:
                cout<<"Rear Value ==> "<<Q1.viewRear();
                break;
            case 7:
                Q1.viewQueue();
                break;
            case 8:
                cout<<"Count ==> "<<Q1.count();
                break;
            default:
                cout<<"InValiD InPut \n";
                break;
        }
        getch();
    }
    return 0;
}
