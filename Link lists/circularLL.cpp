#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

// Singly circular linked list. Only 'tail' is stored; head is always tail->next.
class CList
{
    Node* tail;
    public:
    CList()
    {
        tail=NULL;
    }

    void push_front(int val)
    {
        Node* newnode=new Node(val);
        if(tail==NULL)
        {
            tail=newnode;
            tail->next=tail;   // points to itself
            return;
        }
        newnode->next=tail->next;   // newnode -> old head
        tail->next=newnode;         // tail -> newnode (new head)
    }

    void push_back(int val)
    {
        push_front(val);
        tail=tail->next;   // the node we just added at the front becomes the new tail
    }

    void pop_front()
    {
        if(tail==NULL)
        {
            cout<<"List is empty!"<<endl;
            return;
        }
        Node* head=tail->next;
        if(head==tail)
        {
            delete head;
            tail=NULL;
            return;
        }
        tail->next=head->next;
        head->next=NULL;
        delete head;
    }

    void pop_back()
    {
        if(tail==NULL)
        {
            cout<<"List is empty!"<<endl;
            return;
        }
        Node* head=tail->next;
        if(head==tail)
        {
            delete tail;
            tail=NULL;
            return;
        }
        Node* temp=head;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        temp->next=head;   // new tail points back to head
        delete tail;
        tail=temp;
    }

    // pos is 0-indexed relative to head
    void insert(int val,int pos)
    {
        if(pos<0)
        {
            cout<<"Invalid Position"<<endl;
            return;
        }
        if(tail==NULL && pos>0)
        {
            cout<<"Invalid Position"<<endl;
            return;
        }
        if(pos==0)
        {
            push_front(val);
            return;
        }

        Node* head=tail->next;
        Node* temp=head;
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
            if(temp==head)   // wrapped all the way around: pos was too large
            {
                cout<<"Invalid Position"<<endl;
                return;
            }
        }

        Node* newnode=new Node(val);
        newnode->next=temp->next;
        temp->next=newnode;

        if(temp==tail)   // inserted after the old tail -> newnode is the new tail
        {
            tail=newnode;
        }
    }

    int search(int key)
    {
        if(tail==NULL) return -1;
        Node* head=tail->next;
        Node* temp=head;
        int idx=0;
        do
        {
            if(temp->data==key) return idx;
            temp=temp->next;
            idx++;
        } while(temp!=head);
        return -1;
    }

    void print_list()
    {
        if(tail==NULL)
        {
            cout<<"List is empty;"<<endl;
            return;
        }
        Node* head=tail->next;
        Node* temp=head;
        do
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        } while(temp!=head);
        cout<<"(back to head)"<<endl;
    }
};

int main()
{
    CList cl;
    cl.push_front(1);
    cl.push_front(2);
    cl.push_back(5);
    cl.push_back(4);
    cl.push_front(7);
    cl.pop_front();
    cl.pop_back();
    cl.print_list();

    cl.insert(100,1);
    cl.print_list();
    cout<<"search(5) idx = "<<cl.search(5)<<endl;
}
