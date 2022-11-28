#include<iostream>
#include<stdlib.h>
using namespace std;
class stack
{
    private:
        int top;
        int capacity;
        char *array;
    public:
        stack(int cap)
        {
            top=-1;
            capacity=cap;
            array=(char *)malloc(sizeof(char)*capacity);
        }
        bool isEmpty()
        {
            return top==-1;
        }
        bool isFull()
        {
            return capacity-1==top;
        }
        void push(char c)
        {
            if(isFull())
                cout<<"Stack Is Full\n";
            else
            {
                top++;
                array[top]=c;
            }
        }
        char pop()
        {
            if(isEmpty())
            {
                cout<<"Stack Is Empty\n";
                return '0';
            }
            else
            {
                top--;
                return array[top+1];
            }
        }
        char view()
        {
            return array[top];
        }
};
int main()
{
    int i,j=0;
    stack s(25);
    char A[30],B[30];
    cout<<"Enter InFix Expression ==> ";
    cin>>A;
    s.push('(');
    for(i=0;A[i];i++)
    {
        if(A[i]>='A' && A[i]<='Z')
        {
            B[j]=A[i];
            j++;
        }
        else if(A[i]=='(')
            s.push('(');
        else if(A[i]==')')
            while(s.view()!='(')
            {
                B[j]=s.pop();
                j++;
            }    
        else if(A[i]=='*'||A[i]=='/')
        {
            while(s.view()=='*'||s.view()=='/')
            {
                B[j]=s.pop();
                j++;
            }
            s.push(A[i]);
        }
        else
        {
            while(s.view()=='*'||s.view()=='/' ||s.view()=='+'||s.view()=='-')
            {
                B[j]=s.pop();
                j++;
            }
            s.push(A[i]);
        }
    }
    while(s.view()!='(')
    {
        B[j]=s.pop();
        j++;
    }
    B[j]='\0';
    cout<<"PostFix Expression ==> "<<B;
    return 0;
}
