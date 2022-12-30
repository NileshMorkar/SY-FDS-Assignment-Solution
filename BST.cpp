#include<iostream>
using namespace std;
struct Node
{
    Node *left;
    int data;
    Node *right;
};
class BST
{
    private:
        Node *root;
    public:
        BST(){root=nullptr;}
        void setRoot(Node *r){root=r;}
        Node* getRoot(){return root;}
        bool isEmpty();
        void insertNode(int);
        void viewPostOrder(Node *);
        void viewPreOrder(Node *);
        void viewInOrder(Node *);
        Node* search(int );        
        Node* deleteNode(Node *,int);
        Node* findMax(Node *);     //Predeseccor
        void deleteAllNodes(Node *);//**************************************
        ~BST();//**************************************
};
void BST::deleteAllNodes(Node *root)
{
    if(root)
    {
        deleteAllNodes(root->left);
        deleteAllNodes(root->right);
        delete root;
        cout<<"Deleted SusccessFul\n";
    }
    root=nullptr;
}
BST::~BST()
{
    if(root)
    {
        deleteAllNodes(root->left);
        deleteAllNodes(root->right);
        delete root;
    }
    root=nullptr;
}
Node* BST::search(int data)
{
    Node *t=root;
    while (t)
    {
        if(data < t->data )
            t=t->left;
        else if(data > t->data)
            t=t->right;
        else
            return t;
    }
    return t;
}
Node* BST::findMax(Node *t)
{
    while (t->right)
        t=t->right;
    return t;
}
Node* BST::deleteNode(Node *root,int data)
{
    if(root == NULL)
        cout<<"Data Not Found\n";
    else if(data < root->data)
        root->left = deleteNode(root->left,data);
    else if(data > root->data)
        root->right = deleteNode(root->right,data);
    else
    {   //Element Found
        Node *temp; 
        if(root->left && root->right)   //has Two Nodes
        {
            temp=findMax(root->left);
            root->data=temp->data;
            root->left=deleteNode(root->left,root->data);
        }
        else //single or One Node
        {
            temp=root;
            if(root->left == nullptr)
                root=root->right;
            else if(root->right == nullptr)
                root=root->left;
            delete temp;
        }
    }
    return root;
}
void BST::viewPreOrder(Node *root)
{
    if(root)
    {
        viewPreOrder(root->left);
        cout<<root->data<<"  ";
        viewPreOrder(root->right);
    }
}
void BST::viewPostOrder(Node *root)
{
    if(root)
    {
        viewPostOrder(root->left);
        cout<<root->data<<"  ";
        viewPostOrder(root->right);
    }
}
void BST::viewInOrder(Node *root)
{
    if(root)
    {
        viewInOrder(root->left);
        cout<<root->data<<"  ";
        viewInOrder(root->right);
    }
}
void BST::insertNode(int data)
{
    Node *n=new Node;
    n->left=n->right=nullptr;
    n->data=data;
    if(root==nullptr)
        root=n;
    else
    {
        Node *t=root;
        while (t != n)
        {
            if(data > t->data)
            {
                if(t->right == nullptr)
                    t->right=n;
                t=t->right;
            }
            else if(data < t->data)
            {
                if(t->left == nullptr)
                    t->left=n;
                t=t->left;
            }
            else
                break;
        }
    }
}
bool BST::isEmpty()
{
    return root==nullptr;
}
int main()
{
    BST T1;
    int k;
    while (1)
    {
        cout<<"\n\n1.Insert\n";
        cout<<"2.Search\n";
        cout<<"3.Delete\n";
        cout<<"4.View\n";
        cout<<"5.isEmpty\n";
        cout<<"\n\nEnter Your Choice ==> ";
        cin>>k;
        switch (k)
        {
            case 1:
                cout<<"Enter Your Data ==> ";
                cin>>k;
                T1.insertNode(k);   
                break;
            case 2:
                cout<<"Enter Your Data ==> ";
                cin>>k;
                if(T1.search(k))
                    cout<<"Search SuccessFul\n";
                else
                    cout<<"Search UnsuccessFul\n";   
                break;
            case 3:
                cout<<"Enter Your Data ==> ";
                cin>>k;
                T1.setRoot(T1.deleteNode(T1.getRoot(),k));   
                break;
            case 4:
                cout<<" 1] InOrder\n 2] PreOrder\n 3] PostOrder";
                cout<<"\n\nEnter Your Choice ==> ";
                cin>>k; 
                switch(k)
                {
                    case 1:
                        T1.viewInOrder(T1.getRoot());
                        break;
                    case 2:
                        T1.viewPreOrder(T1.getRoot());
                        break;
                    case 3:
                        T1.viewPostOrder(T1.getRoot());
                        break;
                    default:
                        cout<<"Invalid Choice\n";
                }
                break;
            case 5:
                if(T1.isEmpty())
                    cout<<"Tree Is Empty\n";
                else
                    cout<<"Tree Is Not Empty\n";
                break;
            case 6:
                T1.deleteAllNodes(T1.getRoot());
                break;
            default:
                cout<<"Invalid Choice\n";
        }
    }
    return 0;
}