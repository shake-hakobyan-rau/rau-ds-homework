#include <iostream>

struct ListNode{
int data;
ListNode* next;
ListNode* prev;
explicit ListNode(int val) : data(val), next(nullptr), prev(nullptr){}
};
void erase(ListNode* node){
    if(node == nullptr){ 
    return;
    }
    if(node->prev != nullptr){
    node->prev->next = node->next;    
    }
    if(node->next != nullptr){
    node->next->prev = node->prev;    
    }
    delete node;
}
void printList(ListNode* head){
    ListNode* current = head;
    while(current != nullptr){
        std::cout << current->data;
        if(current->next != nullptr){
        std::cout << " <-> ";    
        }
        current = current->next;
    }
    std::cout << " -> nullptr\n";
}
int main(){
ListNode* node1 = new ListNode(10);
ListNode* node2 = new ListNode(20);
ListNode* node3 = new ListNode(30);
node1->next = node2;
node2->prev = node1;
node3->prev = node2;
std::cout << "before :";  
printList(node1);
erase(node2);
std::cout << "after: ";
printList(node1);
erase(node1);
erase(node3);
return 0;
}
