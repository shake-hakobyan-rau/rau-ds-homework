#include <iostream>

struct ListNode{
int val;
ListNode* next;
ListNode(int x) : val(x), next(nullptr){}
};
ListNode* deleteDublicates(ListNode* head){
if(head == nullptr) return head;
ListNode* current = head;
while(current->next != nullptr){
if(current->val == current->next->val){
    ListNode* dublicate = current->next;
    current->next = current->next->next;    
    delete dublicate;
}
else{
    current = current->next;
}
  }  
return head;   
}
int main(){
ListNode* head = new ListNode(1);
head->next = new ListNode(1);
head->next->next = new ListNode(2);
std::cout << "before: ";
ListNode* current = head;
while(current != nullptr){
std::cout << current->val << " -> ";
current = current->next;
}
std::cout << "nullptr" << std::endl;
head = deleteDublicates(head);    
std::cout << "after: ";
current = head;
while(current != nullptr){
std::cout << current->val << " -> ";   
current = current->next;
}
 std::cout << "nullptr";
 
return 0;   
}

