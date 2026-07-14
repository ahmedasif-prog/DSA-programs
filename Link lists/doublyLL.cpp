#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

class DList
{
    Node* head;
    Node* tail;
    public:
    DList()
    {
        head=tail=NULL;
    }

    void push_front(int val)
    {
        Node* newnode=new Node(val);
        if(head==NULL)
        {
            head=tail=newnode;
            return;
        }
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }

    void push_back(int val)
    {
        Node* newnode=new Node(val);
        if(head==NULL)
        {
            head=tail=newnode;
            return;
        }
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }

    void pop_front()
    {
        if(head==NULL)
        {
            cout<<"List is empty!"<<endl;
            return;
        }
        Node* temp=head;
        if(head==tail)
        {
            head=tail=NULL;
        }
        else
        {
            head=head->next;
            head->prev=NULL;
        }
        temp->next=NULL;
        delete temp;
    }

    void pop_back()
    {
        if(head==NULL)
        {
            cout<<"List is empty!"<<endl;
            return;
        }
        Node* temp=tail;
        if(head==tail)
        {
            head=tail=NULL;
        }
        else
        {
            tail=tail->prev;
            tail->next=NULL;
        }
        temp->prev=NULL;
        delete temp;
    }

    // pos is 0-indexed; inserting at pos==size appends at the end
    void insert(int val,int pos)
    {
        if(pos<0)
        {
            cout<<"Invalid Position"<<endl;
            return;
        }
        if(pos==0)
        {
            push_front(val);
            return;
        }

        Node* temp=head;
        for(int i=0;i<pos-1 && temp!=NULL;i++)
        {
            temp=temp->next;
        }

        if(temp==NULL)
        {
            cout<<"Invalid Position"<<endl;
            return;
        }

        if(temp==tail)
        {
            push_back(val);
            return;
        }

        Node* newnode=new Node(val);
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next->prev=newnode;
        temp->next=newnode;
    }

    int search(int key)
    {
        Node* temp=head;
        int idx=0;
        while(temp!=NULL)
        {
            if(temp->data==key) return idx;
            temp=temp->next;
            idx++;
        }
        return -1;
    }

    void print_list()
    {
        if(head==NULL)
        {
            cout<<"List is empty;"<<endl;
            return;
        }
        Node* temp=head;
        cout<<"NULL <- ";
        while(temp!=NULL)
        {
            cout<<temp->data;
            if(temp->next!=NULL) cout<<" <-> ";
            temp=temp->next;
        }
        cout<<" -> NULL"<<endl;
    }

    void print_reverse()
    {
        if(tail==NULL)
        {
            cout<<"List is empty;"<<endl;
            return;
        }
        Node* temp=tail;
        cout<<"NULL <- ";
        while(temp!=NULL)
        {
            cout<<temp->data;
            if(temp->prev!=NULL) cout<<" <-> ";
            temp=temp->prev;
        }
        cout<<" -> NULL"<<endl;
    }
};

int main()
{
    DList dl;
    dl.push_front(1);
    dl.push_front(2);
    dl.push_back(5);
    dl.push_back(4);
    dl.push_front(7);
    dl.pop_front();
    dl.pop_back();
    dl.print_list();
    dl.print_reverse();

    dl.insert(100,1);
    dl.print_list();
    cout<<"search(5) idx = "<<dl.search(5)<<endl;
}
