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

void removeDuplicates(Node* head) {
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* duplicate = current->next;
            current->next = duplicate->next;
            delete duplicate;
        }
        else {
            current = current->next;
        }
    }
}

void test() {
    Node* a = new Node(1);
    Node* b = new Node(1);
    Node* c = new Node(2);
    Node* d = new Node(3);
    Node* e = new Node(3);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    removeDuplicates(a);

    assert(a->data == 1);
    assert(a->next == c);
    assert(c->data == 2);
    assert(c->next == d);
    assert(d->data == 3);
    assert(d->next == nullptr);

    removeDuplicates(nullptr);

    delete a;
    delete c;
    delete d;
}

int main() {
    test();
    std::cout << "all tests passed";
    return 0;
}
