#include <iostream>
#include <cassert>

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void test() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    assert(findMiddle(a) == c);

    Node* f = new Node(6);
    e->next = f;

    assert(findMiddle(a) == d);
    assert(findMiddle(nullptr) == nullptr);

    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;
}

int main() {
    test();
    std::cout << "all tests passed";
    return 0;
}
