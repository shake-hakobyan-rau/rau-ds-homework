#ifndef FORWARDLIST_H
#define FORWARDLIST_H

template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d = T(), Node* n = nullptr) : data(d), next(n) {}
    };
    
    Node* _head;
    int _size;

public:
    /// 1. Конструктор по умолчанию
    ForwardList() : _head(nullptr), _size(0){}

   
    /// 2. Деструктор
    ~ForwardList(){
        clear();
    }
    
    /// 3. Конструктор копирования
    ForwardList(const ForwardList& other) : _head(nullptr), _size(0){
    if(other._head == nullptr){
     return; 
     } 
    _head = new Node(other._head->data);
    Node* my_car = _head;
    Node* other_car = other._head->next;
    while(other_car != nullptr){
    my_car->next = new Node(other_car->data);
    my_car = my_car->next;
    other_car = other_car->next;
    }
    _size = other._size;    
    }
    /// 4. Оператор присваивания
    ForwardList& operator=(const ForwardList& other){
    if(this != &other){
        clear();
        
    if(other._head != nullptr){
    _head = new Node(other._head->data);
    Node* my_car = _head;
    Node* other_car = other._head->next;
    while(other_car != nullptr){
    my_car->next = new Node(other_car->data);
    my_car = my_car->next;
    other_car = other_car->next;
    }
    }
    _size = other._size;    
    
    }
    return *this;
    }
    /// 5. push_front(const T& x) - добавить в начало
    void push_front(const T& x){
        _head = new Node(x, _head);
        _size++;
    }
    
    /// 6. pop_front() - удалить с начала
    void pop_front(){
        if(_head != nullptr){
            Node* temp = _head;
            _head = _head->next;
            delete temp;
            _size--;
        }
    }
    
    /// 7. front() - первый элемент
    T& front(){
        return _head->data;
    }
    const T& front() const{
        return _head->data;
    }

    /// 8. insert_after(Node* node, const T& value) - вставить после узла
    void insert_after(Node* node, const T& value){
    if(node != nullptr){
        node->next = new Node(value, node->next);
        _size++;
    }    
    }
    
    /// 9. erase_after(Node* node) - удалить после узла
    void erase_after(Node* node){
        if(node != nullptr && node->next != nullptr){
            Node* temp = node->next;
            node->next = temp->next;
            delete temp;
            _size--;
        }
    }
    
    /// 10. clear() - очистить
    void clear(){
    while(_head != nullptr){
        Node* temp = _head;
        _head = _head->next;
        delete temp;
    } 
    _size = 0;   
    }
    
    /// 11. reverse() - развернуть
    void reverse(){
        Node* prev = nullptr;
        Node* curr = _head;
        Node* next_node = nullptr;
        while (curr != nullptr){
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        _head = prev;
    }
    
    /// 12. size() - количество элементов
    int size() const{
        return _size;
    }
    
    /// 13. empty() - пуст ли
    bool empty() const{
        return _head == nullptr;
    }
    
    /// 14. begin() - начало списка
    Node* begin(){
        return _head;
    }
    Node* begin() const{
        return _head;
    }
};

#endif // FORWARDLIST_H
