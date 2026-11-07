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

bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

void test() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);

    a->next = b;
    b->next = c;
    c->next = d;

    assert(hasCycle(a) == false);

    d->next = b;

    assert(hasCycle(a) == true);

    d->next = nullptr;

    assert(hasCycle(a) == false);
    assert(hasCycle(nullptr) == false);

    delete a;
    delete b;
    delete c;
    delete d;
}

int main() {
    test();
    std::cout << "all tests passed";
    return 0;
}
