#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class Stack
{
    Node* top;
    public:
    Stack()
    {
        top = NULL;
    }
    void push(int val)
    {
        Node* newnode = new Node(val);
        if(top == NULL)
        {
            top = newnode;
            return;
        }
        newnode->next=top;
        top = newnode;
    }
    void pop()
    {
        if(top==NULL)
        {
            cout<<"Stack underflow!"<<endl;
            return;
        }
        Node* temp = top;
        top = temp->next;
        temp->next = NULL;
        delete temp;
    }
    void peek()
    {
        if(top == NULL)
        {
            cout<<"Stack Underflow!"<<endl;
            return;
        }
        cout<<top->data<<endl;
    }
    void display()
    {
        Node* temp = top;
        while(temp!=NULL)
        {
            
            cout<<temp->data;
            if(temp->next!=NULL)
            {
                cout<<" -> ";
            }
            temp = temp->next;
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