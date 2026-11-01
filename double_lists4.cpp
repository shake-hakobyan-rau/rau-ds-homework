#include <iostream>

struct ListNode{
int data;    
ListNode* next;
ListNode* prev;
explicit ListNode(int val) : data(val), next(nullptr), prev(nullptr){}
};
ListNode* reverse(ListNode* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode* current = head;
    ListNode* temp = nullptr;
    while(current != nullptr){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        head = current;
        current = current->prev;
      }    
   
    
    return head;
   
}
int main(){
ListNode* n1 = new ListNode(10);    
ListNode* n2 = new ListNode(20);
ListNode* n3 = new ListNode(30);

n1->next = n2;
n2->prev = n1;
n3->prev = n2;
n2->next = n3;
ListNode* newHead = reverse(n1);
ListNode* current = newHead; 
while(current != nullptr){
std::cout << current->data;
if(current->next != nullptr){
    std::cout <<  " <-> ";
} 
current = current->next;
}
std::cout << " -> nullptr\n";   

return 0;
}
