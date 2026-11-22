#include <iostream>
#include <utility>

struct ListNode{
int data;    
ListNode* next;
ListNode* prev;
explicit ListNode(int val) : data(val), next(nullptr), prev(nullptr){}  
};
void sort(ListNode* head){
    if(head == nullptr) return;
    bool swapped;    
    ListNode* ptr1;
    ListNode* lptr = nullptr;
    do{
        swapped = false;
        ptr1 = head;
        while(ptr1->next != lptr){
            if(ptr1->data > ptr1->next->data){
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        }while(swapped);
     }   


    int main(){
    ListNode* n1 = new ListNode(30);
    ListNode* n2 = new ListNode(10);
    ListNode* n3 = new ListNode(20);
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    std::cout << "before: ";
    ListNode* curr = n1;
    while(curr != nullptr){
        std::cout << curr->data << (curr->next ? " < - > " : "");
        curr = curr->next;
    }
    std::cout << " -> nullptr\n ";
    sort(n1);
    std::cout << "after: " ;
    curr = n1;
    while(curr != nullptr){
        std::cout << curr->data << (curr->next ? " <-> " : "");
        curr = curr->next;
    }
    std::cout << " -> nullptr\n ";
    return 0;
    }

