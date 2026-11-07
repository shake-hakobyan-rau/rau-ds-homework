#include "Stack.h"
#include <cassert>
#include <iostream>

// Реализуйте методы Stack<T>:
//   1. Stack()                         - конструктор
//   2. ~Stack()                        - деструктор
//   3. Stack(const &)                  - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. push(const T&)                  - добавить
//   6. pop()                           - удалить
//   7. top()                           - вершина
//   8. size()                          - размер
//   9. capacity()                      - вместимость
//  10. is_empty()                      - пусто ли
//  11. clear()                         - очистить
//  12. peek()                          - просмотреть вершину
//  13. ...
//  14. ...

void test_push() {
    Stack<int> s;
    
    s.push(5);
    assert(s.size() == 1);
    assert(s.top() == 5);
    
    s.push(10);
    s.push(15);
    assert(s.size() == 3);
    assert(s.top() == 15);
    
    std::cout << "test_push passed" << std::endl;
}

 void test_pop() {
  Stack<int> s;
  s.push(3);
  s.push(5);
  s.push(7);
  s.pop();
  assert(s.size() == 2);
  assert(s.top() == 5);   
 }
std::cout << "test_pop passed" << std::endl;
// void test_top() { ... }
void test_top(){
Stack<int> s;

s.push(3);
s.push(5);
s.push(7);
assert(s.top() == 7);
std::cout << "test_top passed" << std::endl;    
}
void test_size(){
Stack<int> s;
s.push(3);
s.push(5);
s.push(7);
assert(s.size() == 3);
std::cout << "test_size passed" << std::endl; 
}
void test_capacity(){
Stack<int> s;
s.push(1);
s.push(5);
s.push(15);
s.push(8);
assert(s.capacity() == 4);
std::cout << "test_capacity passed" << std::endl; 
}
void test_is_empty(){
Stack<int> s;
assert(s.is_empty() == true);
}
void test_clear(){
Stack<int> s;
s.push(5);
s.clear();
assert(s.size() == 0);
std::cout << "test_clear() passed" << std::endl;
}
void test_peek(){
Stack<int> s;
s.push(3);
s.push(9);
s.push(5);
assert(s.peek() == 5);
std::cout << "test_peek() passed" << std::endl;
}
int main() {
    std::cout << "Running Stack tests" << std::endl;
    test_push();
    std::cout << "All tests passed" << std::endl;
    return 0;
}
