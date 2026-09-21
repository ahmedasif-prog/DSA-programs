bool removeCycle(Node* head) {
    Node *slow = head, *fast = head;

    // Phase 1: detect cycle (Floyd's)
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (!fast || !fast->next) return false;  // no cycle

    // Phase 2: find cycle start
    slow = head;
    if (slow == fast) {
        // cycle starts at head: walk to the last node in the cycle
        while (fast->next != slow) fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // fast is now the last node of the cycle
    fast->next = nullptr;
    return true;
}
Node* flatten(Node* head) {
    for (Node* curr = head; curr; curr = curr->next) {
        if (!curr->child) continue;

        Node* child = curr->child;
        Node* tail = child;
        while (tail->next) tail = tail->next;

        // splice child list between curr and curr->next
        tail->next = curr->next;
        if (curr->next) curr->next->prev = tail;

        curr->next = child;
        child->prev = curr;
        curr->child = nullptr;
    }
    return head;
}
 void specified_reverse(int start,int end)
    {
        if(head==NULL)
        {
            cout<<"List is empty!"<<endl;
            return;
        }
        if(start>len()||end>len()||start<0||end<0) return;
        Node* prev = NULL;
        Node* curr = head;
        for(int i=1;i<start;i++)
        {
            Node* prev = curr;
            Node* curr = curr->next;
        }
        Node* before = prev;
        Node* first = curr;
        
        for(int i=start;i<=end;i++)
        {
            Node* next = curr->next;
            curr->next=prev;
            prev = curr;
            curr = next;
        }
         first->next = curr;    
        if (before == NULL) head = prev;
        else before->next = prev;

    }
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

// Reverse the whole list
Node* reverse(Node* head) {
    Node *prev = nullptr, *curr = head;
    while (curr) {
        Node* nxt = curr->next;  // save next
        curr->next = prev;       // flip pointer
        prev = curr;
        curr = nxt;
    }
    return prev;  // new head
}

// Swap nodes in pairs: 1 2 3 4 5 -> 2 1 4 3 5
Node* swapPairs(Node* head) {
    Node dummy(0);
    dummy.next = head;
    Node* prev = &dummy;

    while (prev->next && prev->next->next) {
        Node* a = prev->next;
        Node* b = a->next;

        a->next = b->next;  // a points past the pair
        b->next = a;        // b points to a
        prev->next = b;     // previous part points to b

        prev = a;           // a is now the tail of the swapped pair
    }
    return dummy.next;
}

Node* build(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 1; i <= n; i++) {
        Node* node = new Node(i);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    return head;
}

void printList(Node* head) {
    for (; head; head = head->next) {
        cout << head->val;
        if (head->next) cout << " -> ";
    }
    cout << "\n";
}

void freeList(Node* head) {
    while (head) { Node* t = head->next; delete head; head = t; }
}

int main() {
    Node* h = build(5);
    printList(h);           // 1 -> 2 -> 3 -> 4 -> 5

    h = reverse(h);
    printList(h);           // 5 -> 4 -> 3 -> 2 -> 1

    h = swapPairs(h);
    printList(h);           // 4 -> 5 -> 2 -> 3 -> 1

    freeList(h);
    return 0;
}
ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode* prev = NULL;
    ListNode* first = head;
    ListNode* sec = head->next;

    while (first != NULL && sec != NULL) {
        ListNode* third = sec->next;

        sec->next = first;      // sec goes in front of first
        first->next = third;    // first points past the pair

        if (prev != NULL) {
            prev->next = sec;   // link previous pair to sec
        } else {
            head = sec;         // first pair: sec becomes new head
        }

        // update
        prev = first;           // first is now the tail of the swapped pair
        first = third;
        if (third != NULL) {
            sec = third->next;
        } else {
            sec = NULL;
        }
    }

    return head;
}
