#include<iostream>
using namespace std;
class Stack
{
    int arr[5];
    int top;
    public:
    Stack()
    {
        top = -1;
    }
    void push(int val){
        if(top==4)
        {
            cout<<"Stack overflow!"<<endl;
            return;
        }
        top++;
        arr[top] = val;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack Underflow!"<<endl;
            return;
        }
        top--;
    }
    void peek()
    {
        if (top == -1)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<arr[top]<<endl;
    }
    void display()
    {
        if (top == -1)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        for (int i=0;i<=top;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(3);
    s.pop();
    s.push(4);
    s.peek();
    s.display();
}