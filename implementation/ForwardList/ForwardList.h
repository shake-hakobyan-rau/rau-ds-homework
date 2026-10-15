#ifndef FORWARDLIST_H
#define FORWARDLIST_H

template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
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
        if (other._head == nullptr){
            return;
        }
        _head = new Node(other._head->data);
        _size = 1;
        Node* current = other._head->next;
        Node* last = _head;
        while (current != nullptr){
            last->next = new Node(current->data);
            last = last->next;
            current = current->next;
            _size++;
        }
    }
    
    /// 4. Оператор присваивания
    ForwardList& operator=(const ForwardList& other){
        if (this == &other){
            return *this;
        }
        clear();
        if (other._head == nullptr){
            return *this;
        }
        _head = new Node(other._head->data);
        _size = 1;
        Node* current = other._head->next;
        Node* last = _head;
        while (current != nullptr){
            last->next = new Node(current->data);
            last = last->next;
            current = current->next;
            _size++;
        }
        return *this;
    }
    
    /// 5. push_front(const T& x) - добавить в начало
    void push_front(const T& x){
        Node* new_node = new Node(x);
        new_node->next = _head;
        _head = new_node;
        _size++;
    }
    
    /// 6. pop_front() - удалить с начала
    void pop_front(){
        if (_head == nullptr){
            return;
        }
        Node* temp = _head;
        _head = _head->next;
        delete temp;
        _size--;
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
        if (node == nullptr){
            return;
        }
        Node* new_node = new Node(value);
        new_node->next = node->next;
        node->next = new_node;
        _size++;
    }
    
    /// 9. erase_after(Node* node) - удалить после узла
    void erase_after(Node* node){
        if (node == nullptr){
            return;
        }
        if (node->next == nullptr){
            return;
        }
        Node* temp = node->next;
        node->next = temp->next;
        delete temp;
        _size--;
    }
    
    /// 10. clear() - очистить
    void clear(){
        while (_head != nullptr){
            Node* temp = _head;
            _head = _head->next;
            delete temp;
        }
        _size = 0;
    }
    
    /// 11. reverse() - развернуть
    void reverse(){
        Node* previous = nullptr;
        Node* current = _head;
        Node* next = nullptr; 
        while (current != nullptr){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        _head = previous;
    }
    
    /// 12. size() - количество элементов
    int size() const{
        return _size;
    }
    
    /// 13. empty() - пуст ли
    bool empty() const{
        return _size == 0;
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
