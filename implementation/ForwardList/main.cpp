#include "ForwardList.h"
#include <cassert>
#include <iostream>

// Реализуйте методы ForwardList<T>:
//   1. ForwardList()                   - конструктор
//   2. ~ForwardList()                  - деструктор
//   3. ForwardList(const &)            - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. push_front(const T&)            - добавить в начало
//   6. pop_front()                     - удалить с начала
//   7. front()                         - первый элемент
//   8. insert_after(Node*, const T&)   - вставить после узла
//   9. erase_after(Node*)              - удалить после узла
//  10. clear()                         - очистить
//  11. reverse()                       - развернуть
//  12. size()                          - размер
//  13. empty()                         - пусто ли
//  14. begin()                         - начало списка

void test_push_front() {
    ForwardList<int> list;
    
    list.push_front(1);
    assert(list.size() == 1);
    assert(list.front() == 1);
    
    list.push_front(2);
    list.push_front(3);
    assert(list.size() == 3);
    assert(list.front() == 3);
    
    std::cout << "test_push_front passed" << std::endl;
}

 void test_pop_front() {
 ForwardList<int> list;
 list.push_front(10);
 list.push_front(20);
 list.pop_front();
assert(list.size() == 1);
assert(list.front() == 10);
list.pop_front();
assert(list.size() == 0);
assert(list.empty() == true);
std::cout << "test_pop_front passed" << std::endl;
 }

 void test_front() {
 ForwardList<int> list;
 list.push_front(1);
 assert(list.front() == 1);
 list.front() = 7;
 assert(list.front() == 7);
 std::cout << "test_front passed" << std::endl;
}
void test_insert_after(){
ForwardList<int> list;
list.push_front(1);
auto* head_node = list.begin();
list.insert_after(head_node, 2);
assert(list.size() == 2);
assert(head_node->next != nullptr);
assert(head_node->next->data == 2);
std::cout << "test_insert_after passed" <<std::endl;
}
void test_erase_after(){
ForwardList<int> list;
list.push_front(3);
list.push_front(2);
list.push_front(1);
auto* head_node = list.begin();
list.erase_after(head_node);
assert(list.size() == 2);
assert(head_node->next->data == 3);
std::cout << "test_erase_after passed";
}
void test_clear(){
ForwardList<int> list;
list.push_front(1);
list.push_front(2);
list.clear();
assert(list.size() == 0);
assert(list.empty() == true);
assert(list.begin() == nullptr);
std::cout << "test_clear passed";    
}
void test_reverse(){
ForwardList<int> list;
list.push_front(3);
list.push_front(2);
list.push_front(1);
list.reverse();
assert(list.front() == 3);
auto* node = list.begin();
assert(node->data == 3);
assert(node->next->data ==2);
assert(node->next->next->data == 1);
std::cout << "test_reverse passed";
}
void test_copy_and_assignment(){
ForwardList<int> list1;
list1.push_front(2);
list1.push_front(3);
ForwardList<int> list2(list1);
assert(list2.size() == 2);
assert(list2.front() == 3);
ForwardList<int> list3;
list3 = list1;
assert(list3.size() == 2);
assert(list3.front() == 3);
std::cout << "test_copy_and_assignment passed";    
}
int main() {
    std::cout << "Running ForwardList tests" << std::endl;
    test_push_front();
    test_pop_front();
    test_front();
    test_insert_after();
    test_erase_after();
    test_clear();
    test_reverse();
    test_copy_and_assignment();
    std::cout << "All tests passed" << std::endl;
    return 0;
}
