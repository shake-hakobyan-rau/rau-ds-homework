#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
private:
    T* _data;
    int _capacity;
    int _size;
    
    void expand(){
    _capacity *= 2;
    T* newData = new T[_capacity];
    for(int i = 0; i < _size; ++i){
    newData[i] = _data[i];
    }   
    delete[] _data;
    _data = newData;
    }
 public:   
    Stack(){
    _capacity = 4;
    _size = 0;
    _data = new T[_capacity]; /// 1. Конструктор по умолчанию   
    }

    
    ~Stack(){
    delete[] _data;  /// 2. Деструктор   
    }
    
   /// 3. Конструктор копирования
     Stack(const Stack& other){
     _capacity = other._capacity;
     _size = other._size;
     _data = new T[_capacity];
     for(int i = 0; i < _size; i++){
     _data[i] = other._data[i];  
     }   
     }
    Stack& operator=(const Stack& other){ /// 4. Оператор присваивания
    if(this != &other){    
    delete[] _data;
    _capacity = other._capacity;
     _size = other._size;
     _data = new T[_capacity];
     for(int i = 0; i < _size; i++){
     _data[i] = other._data[i];  
     }   
     }
     return *this;
    }
    void push(const T& x){ /// 5. push(const T& x) - добавить в стек
    if(_size == _capacity){
    expand();    
    }
    _data[_size] = x;
    _size++;
}
    void pop(){ /// 6. pop() - удалить с вершины
    if(_size > 0){
    _size--;    
    }
    }
    T& top(){/// 7. top() - вершина стека
    return _data[_size - 1];
    }
    const T& top()const{
    return _data[_size - 1];    
    } 
    
    /// 8. size() - количество элементов
    int size() const{
    return _size;    
    }
    /// 9. capacity() - вместимость
    int capacity() const{
    return _capacity;    
    }
    
    /// 10. is_empty() - пуст ли
    bool is_empty() const{
    return _size == 0;    
    }
    
    /// 11. clear() - очистить
    void clear(){
    _size = 0;    
    }
    
    /// 12. peek() - посмотреть вершину без удаления
    T& peek(){
    return _data[_size - 1];    
    }
    const T& peek() const{
    {
    return _data[_size - 1];    
    }    
    }
};

#endif // STACK_H

