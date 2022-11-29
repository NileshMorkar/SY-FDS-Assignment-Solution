#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int EvaluatePostFix(char B[]);
template<class X>
class stack
{
    private:
        int top;
        int capacity;
        X *array;
    public:
        stack(int cap)
        {
            top=-1;
            capacity=cap;
            array=(X *)malloc(sizeof(X)*capacity);
        }
        bool isEmpty()
        {
            return top==-1;
        }
        bool isFull()
        {
            return capacity-1==top;
        }
        void push(X c)
        {
            if(isFull())
                cout<<"Stack Is Full\n";
            else
            {
                top++;
                array[top]=c;
            }
        }X pop()
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
        X view()
        {
            return array[top];
        }
};
int main()
{
    int i,j=0;
    stack <char>s(25);
    char A[30],B[30];
    cout<<"Enter InFix Expression ==> ";
    cin>>A;
    //s.push('(');
    for(i=0;A[i];i++)
    {
        if(A[i]>='1' && A[i]<='9')
        {
            B[j]=A[i];
            j++;
        }
        else if(A[i]=='(' || A[i]=='^')
            s.push(A[i]);
        else if(A[i]==')')
        {
            while(s.view()!='(')
            {
                B[j]=s.pop();
                j++;
            }    
            s.pop();
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
    while(s.isEmpty()!=true)
    {
        B[j]=s.pop();
        j++;
    }
    B[j--]='\0';
    cout<<"PostFix Expression ==> "<<B;
    cout<<"\nResult==>"<<EvaluatePostFix(B);
    
    return 0;
}
int EvaluatePostFix(char B[])
{
    int i,n1,n2;
    stack <int>S(25);
    for(i=0;B[i];i++)
    {
        if(isdigit(B[i]))
            S.push(B[i]-48);
        else
        {
            n1=S.pop();
            n2=S.pop();
            switch(B[i])
            {
                case '+':
                    S.push(n2+n1);
                    break;
                case '-':
                    S.push(n2-n1);
                    break;
                case '*':
                    S.push(n2*n1);
                    break;
                case '/':
                    S.push(n2/n1);
                    break;
                case '^':
                    S.push((int)pow(n2,n1));
                    break;
            }
        }
    }
    return S.pop();
}
