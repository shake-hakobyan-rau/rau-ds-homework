#include <iostream>
#include <cassert>

struct ListNode {
    int data;
    ListNode* prev;
    ListNode* next;
    ListNode(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

void erase(ListNode* node) {
    if (node == nullptr) {
        return;
    }
    if (node->prev != nullptr) {
        node->prev->next = node->next;
    }
    if (node->next != nullptr) {
        node->next->prev = node->prev;
    }
    delete node;
}

void test() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);

    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;

    erase(b);

    assert(a->next == c);
    assert(c->prev == a);

    erase(c);
    assert(a->next == nullptr);

    erase(nullptr);

    delete a;
}

int main() {
    test();
    std::cout << "all tests passed";
    return 0;
}
