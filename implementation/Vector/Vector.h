#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

template <typename T>
class Vector {
private:
    T* _data;
    size_t _size;
    size_t _capacity;
    
    void _resize_capacity(size_t new_capacity);

public:
    
    
    /// 1. Конструктор по умолчанию
    Vector() : _data(nullptr), _size(0), _capacity(0) {}
    
    /// 2. Конструктор с начальным размером
    Vector(size_t initial_size) {
    _size = initial_size;
    _capacity = initial_size;
    if(initial_size > 0){
    _data = new T[initial_size]();
    }
    else{
    _data = nullptr;
    }
}
    /// 3. Деструктор
    ~Vector(){
    delete[] _data;
    }
    /// 4. Конструктор копирования
    Vector(const Vector& other){
    _size = other._size;
    _capacity = other._capacity;
    if(_capacity > 0){
    _data = new T[_capacity];
    for(size_t i = 0; i < _size; i++){
    _data[i] = other._data[i];   
    }
    }
    else{
    _data = nullptr;
    }
}
    /// 5. Оператор присваивания
    Vector& operator=(const Vector& other){
    if(this != &other){
    delete[]_data;
    _size = other._size;
    _capacity = other._capacity;
    if(_capacity > 0){
    _data = new T[_capacity];
    for(size_t i = 0; i < _size; i++){
    _data[i] = other._data[i];   
    }
    }
    else{
    _data = nullptr;
    }
}
    return *this;    
    }     
    
    
    /// 6. push_back(const T& value){ - добавить в конец
    void push_back(const T& value){
    if(_size == _capacity){
    size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
    T* new_data = new T[new_capacity];
    for(size_t i = 0; i < _size; i++){
    new_data[i] = _data[i];
    }
    delete[] _data;
    _data = new_data;
    _capacity = new_capacity;
    }
    _data[_size] = value;

    _size++;
}
    /// 7. pop_back() - удалить последний элемент
    void pop_back(){
    if(_size > 0){
        _size--;    
   } 
}/// 8. operator[](size_t index) - доступ по индексу
    T& operator[](size_t index){
    return _data[index];
    }
    const T& operator[](size_t index) const{
    return _data[index];    
    }
    /// 9. at(size_t index) - доступ с проверкой границ
    T& at(size_t index){
        if(index >= _size){
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }
    const T& at(size_t index) const{
        if(index >= _size){
         throw  std::out_of_range("Index out of range");
        }
        return _data[index];
    }  
    /// 10. front() - первый элемент
    T& front(){
    if(_size == 0){
        throw std::out_of_range("is empty");

    }    
    return _data[0];
    }
    const T& front() const{
    if(_size == 0){
    throw std::out_of_range("is empty");
    }    
            
        
    return _data[0];
    }
    /// 11. back() - последний элемент
    T& back(){
    return _data[_size - 1];
    }
    const T& back() const{
    if(_size == 0){    
    throw std::out_of_range("is empty");
    }
    return _data[_size - 1];
    }
    /// 12. size() - количество элементов
    size_t size() const{
    return _size;    
    }
    /// 13. capacity() - выделенная память
    size_t capacity() const{
    return _capacity;
    }
    /// 14. empty() - пуст ли вектор
    bool empty() const{
    return _size == 0;    
    }
    /// 15. reserve(size_t new_capacity) - выделить память
    void reserve(size_t new_capacity){
    if(new_capacity > _capacity){
    T* new_data = new T[new_capacity];
    for(size_t i = 0; i < _size; i++){
    new_data[i] = _data[i];
    }
    delete[] _data;
    _data = new_data;
    _capacity = new_capacity;
    }
}
    /// 16. clear() - очистить вектор
    void clear(){
    _size = 0;
    }
    /// 17. begin() - начало вектора
    T* begin(){
        return _data;
    }
    const T* begin() const{
        return _data;
    }
    /// 18. end() - конец вектора
    T* end(){
        return _data + _size;
    }
    const T* end() const{
        return _data + _size;
    }
};

#endif // VECTOR_H
