#include "Vector.h"
#include <cassert>
#include <iostream>

// Реализуйте методы Vector<T>:
//
//   1. Vector()                        - конструктор по умолчанию
//   2. ~Vector()                       - деструктор
//   3. Vector(const Vector& other)     - конструктор копирования
//   4. operator=(const Vector& other)  - оператор присваивания
//   5. push_back(const T& x)           - добавить в конец
//   6. pop_back()                      - удалить с конца
//   7. operator[](int index)           - доступ по индексу
//   8. back()                          - последний элемент
//   9. insert(int pos, const T& val)   - вставить
//  10. erase(int pos)                  - удалить
//  11. swap(Vector& other)             - обменять содержимое
//  12. clear()                         - очистить
//  13. resize(int new_size)            - изменить размер
//  14. front()                         - первый элемент
//
// Напишите для каждой функции один тест:
//   void test_<название_функции>() { ... }
//
// Каждый тест должен проверять:
//   - Нормальный случай
//   - Граничные случаи


void test_push_back() {
    Vector<int> v;
    
    // Нормальный случай
    v.push_back(5);
    assert(v.size() == 1);
    assert(v[0] == 5);
    
    v.push_back(10);
    v.push_back(15);
    assert(v.size() == 3);
    assert(v.back() == 15);
    
    std::cout << "test_push_back passed" << std::endl;
}

 void test_pop_back() { 
 Vector<int> v;
v.push_back(5);
v.push_back(10);
v.pop_back();
assert(v.size() == 1);
assert(v.back() == 5);
v.pop_back();
assert(v.size() == 0);
std::cout << "test_pop_back passed" << std::endl;
} 
 void test_operator_bracket() {
  Vector<int> v;
v.push_back(5);
v.push_back(10);
assert(v[0] == 5); 
assert(v[1] == 10); 
v[0] = 50;
assert(v[0] == 50);
std::cout << "test_operator_bracket passed" << std::endl;
}


 void test_back() {
  Vector<int> v;
v.push_back(5);
assert(v.back() == 5);
v.push_back(10);
assert(v.back() == 10);
std::cout << "test_back passed" << std::endl;
}
 
 void test_front() {
  Vector<int> v;
v.push_back(5);
assert(v.front() == 5);
v.push_back(10);
assert(v.front() == 5);
std::cout << "test_front passed" << std::endl;
}
 
void test_clear() {
  Vector<int> v;
v.push_back(5);
v.push_back(10);
v.clear();
assert(v.size() == 0);
v.clear();
assert(v.size() == 0);
std::cout << "test_clear passed" << std::endl;
}
 
void test_begin_end() {
  Vector<int> v;
v.push_back(100);
v.push_back(200);
assert(*(v.begin()) == 100);
assert((v.end() - v.begin()) == 2);
std::cout << "test_begin_end passed" << std::endl;
}
void test_empty() {
  Vector<int> v;
assert(v.empty() == true);
v.push_back(5);
assert(v.empty() == false);
std::cout << "test_empty passed" << std::endl;

}

void test_at() {
  Vector<int> v;
v.push_back(5);
v.push_back(10);
assert(v.at(0) == 5);
assert(v.at(1) == 10);
v.at(0) = 50;
assert(v.at(0) == 50);
try{
v.at(2);
assert(false);    
}
catch(const std::out_of_range& e){

}
std::cout << "test_at passed" << std::endl;
}
void test_reserve(){
  Vector<int> v;
v.reserve(10);
assert(v.capacity() == 10);
assert(v.size() == 0);
v.reserve(5);
assert(v.capacity() == 10);
std::cout << "test_reserve passed" << std::endl;

}

int main() { 

 std::cout << "Running Vector tests" << std::endl;
 test_push_back();
 test_pop_back();
 test_operator_bracket();
 test_at();
 test_front();
 test_back();  
 test_clear();   
 test_empty();  
 test_begin_end();
 test_reserve();   
    // Добавляйте свои тесты:
    // test_pop_back();
    // test_operator_bracket();
    
    std::cout << "All tests passed" << std::endl;
    return 0;
}
