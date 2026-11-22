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

void sort(ListNode* head) {
    if (head == nullptr) {
        return;
    }
    bool swapped = true;
    while (swapped) {
        swapped = false;
        ListNode* current = head;
        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    }
}

void test() {
    ListNode* a = new ListNode(4);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(5);
    ListNode* d = new ListNode(1);
    ListNode* e = new ListNode(3);

    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    c->next = d;
    d->prev = c;
    d->next = e;
    e->prev = d;

    sort(a);

    assert(a->data == 1);
    assert(b->data == 2);
    assert(c->data == 3);
    assert(d->data == 4);
    assert(e->data == 5);

    assert(a->next == b);
    assert(b->prev == a);
    assert(d->next == e);
    assert(e->prev == d);

    sort(nullptr);

    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
}

int main() {
    test();
    std::cout << "all tests passed";
    return 0;
}
