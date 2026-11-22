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

ListNode* reverse(ListNode* head) {
    ListNode* current = head;
    ListNode* newHead = nullptr;
    while (current != nullptr) {
        ListNode* temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        newHead = current;
        current = current->prev;
    }
    return newHead;
}

void test() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);

    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;

    ListNode* head = reverse(a);

    assert(head == c);
    assert(c->next == b);
    assert(b->next == a);
    assert(a->next == nullptr);

    assert(c->prev == nullptr);
    assert(b->prev == c);
    assert(a->prev == b);

    assert(reverse(nullptr) == nullptr);

    delete a;
    delete b;
    delete c;
}

int main() {
    test();
    std::cout << "all tests passed";
    return 0;
}
