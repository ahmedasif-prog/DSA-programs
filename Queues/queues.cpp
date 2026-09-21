#include <iostream>
using namespace std;

// ---------- 1. Queue using Array (linear) ----------
class ArrayQueue {
    int *arr;
    int front, rear, capacity;
public:
    ArrayQueue(int size = 5) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }
    ~ArrayQueue() { delete[] arr; }

    bool isEmpty() { return front > rear; }
    bool isFull()  { return rear == capacity - 1; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue Overflow\n"; return; }
        arr[++rear] = x;
    }
    int dequeue() {
        if (isEmpty()) { cout << "Queue Underflow\n"; return -1; }
        return arr[front++];
    }
    int peek() {
        if (isEmpty()) { cout << "Queue is empty\n"; return -1; }
        return arr[front];
    }
    void display() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

// ---------- 2. Queue using Linked List ----------
class LinkedQueue {
    struct Node {
        int data;
        Node *next;
        Node(int d) : data(d), next(nullptr) {}
    };
    Node *front, *rear;
public:
    LinkedQueue() : front(nullptr), rear(nullptr) {}
    ~LinkedQueue() { while (!isEmpty()) dequeue(); }

    bool isEmpty() { return front == nullptr; }

    void enqueue(int x) {
        Node *n = new Node(x);
        if (isEmpty()) front = rear = n;
        else { rear->next = n; rear = n; }
    }
    int dequeue() {
        if (isEmpty()) { cout << "Queue Underflow\n"; return -1; }
        Node *temp = front;
        int val = temp->data;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        return val;
    }
    int peek() {
        if (isEmpty()) { cout << "Queue is empty\n"; return -1; }
        return front->data;
    }
    void display() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        for (Node *t = front; t; t = t->next) cout << t->data << " ";
        cout << endl;
    }
};

// ---------- 3. Circular Queue (array) ----------
class CircularQueue {
    int *arr;
    int front, rear, count, capacity;
public:
    CircularQueue(int size = 5) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }
    ~CircularQueue() { delete[] arr; }

    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == capacity; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue Overflow\n"; return; }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
    }
    int dequeue() {
        if (isEmpty()) { cout << "Queue Underflow\n"; return -1; }
        int val = arr[front];
        front = (front + 1) % capacity;
        count--;
        return val;
    }
    int peek() {
        if (isEmpty()) { cout << "Queue is empty\n"; return -1; }
        return arr[front];
    }
    void display() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        for (int i = 0; i < count; i++)
            cout << arr[(front + i) % capacity] << " ";
        cout << endl;
    }
};

int main() {
    cout << "Array Queue:\n";
    ArrayQueue aq(5);
    for (int i = 1; i <= 5; i++) aq.enqueue(i * 10);
    aq.display();
    aq.dequeue();
    aq.display();

    cout << "\nLinked List Queue:\n";
    LinkedQueue lq;
    for (int i = 1; i <= 5; i++) lq.enqueue(i * 10);
    lq.display();
    lq.dequeue();
    lq.display();

    cout << "\nCircular Queue:\n";
    CircularQueue cq(5);
    for (int i = 1; i <= 5; i++) cq.enqueue(i * 10);
    cq.display();
    cq.dequeue();
    cq.dequeue();
    cq.enqueue(60);   // reuses freed space
    cq.enqueue(70);
    cq.display();

    return 0;
}