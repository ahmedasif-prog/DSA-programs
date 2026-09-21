#include <iostream>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Queue Class
class Queue {
private:
    Node* front;
    Node* rear;

public:

    // Constructor
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Enqueue Operation
    void enqueue(int value) {

        Node* newNode = new Node(value);

        // If queue is empty
        if (front == NULL) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " inserted into queue." << endl;
    }

    // Dequeue Operation
    void dequeue() {

        if (front == NULL) {
            cout << "Queue Underflow! Queue is empty." << endl;
            return;
        }

        Node* temp = front;

        cout << temp->data << " removed from queue." << endl;

        front = front->next;

        // If queue becomes empty
        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    // Peek Operation
    void peek() {

        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Front element: " << front->data << endl;
    }

    // Display Operation
    void display() {

        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;

        cout << "Queue elements (Front to Rear):" << endl;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Check if Queue is Empty
    bool isEmpty() {
        return front == NULL;
    }
};


int main() {

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << endl;

    q.display();

    cout << endl;

    q.peek();

    cout << endl;

    q.dequeue();

    cout << endl;

    q.display();

    return 0;
}
