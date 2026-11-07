#include <iostream>

struct ListNode{
int data;
ListNode* next;
explicit ListNode(int val) : data(val), next(nullptr){}
};
ListNode* findMiddle(ListNode* head){
   ListNode* slow = head;
   ListNode* fast = head;
   while(fast != nullptr && fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
   }   
   return slow;
}
int main(){
ListNode* head = new ListNode(1);
head->next = new ListNode(2);
head->next->next = new ListNode(3);
head->next->next->next = new ListNode(4);
head->next->next->next->next = new ListNode(5);
ListNode* mid = findMiddle(head);
if(mid != 0){
 std::cout << mid->data;   
}    

 return 0;   
}
    

