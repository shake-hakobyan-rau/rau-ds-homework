#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>

template <typename T>
class Vector {
private:
    T* _data;
    size_t _size;
    size_t _capacity;

    void _resize_capacity(size_t new_capacity) {
        if (new_capacity < _size) {
            throw std::length_error("New capacity is too small");
        }

        if (new_capacity == _capacity) {
            return;
        }

        T* new_data = new_capacity > 0 ? new T[new_capacity]() : nullptr;

        try {
            for (size_t i = 0; i < _size; ++i) {
                new_data[i] = _data[i];
            }
        } catch (...) {
            delete[] new_data;
            throw;
        }

        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }

public:
    // 1. Конструктор по умолчанию
    Vector()
        : _data(nullptr), _size(0), _capacity(0) {}

    // 2. Конструктор с начальным размером
    Vector(size_t initial_size)
        : _data(initial_size > 0 ? new T[initial_size]() : nullptr),
          _size(initial_size),
          _capacity(initial_size) {}

    // 3. Деструктор
    ~Vector() {
        delete[] _data;
    }

    // 4. Конструктор копирования
    Vector(const Vector& other)
        : _data(other._capacity > 0
                    ? new T[other._capacity]()
                    : nullptr),
          _size(other._size),
          _capacity(other._capacity) {
        try {
            for (size_t i = 0; i < _size; ++i) {
                _data[i] = other._data[i];
            }
        } catch (...) {
            delete[] _data;
            throw;
        }
    }

    // 5. Оператор присваивания
    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }

        Vector temp(other);

        T* old_data = _data;
        _data = temp._data;
        _size = temp._size;
        _capacity = temp._capacity;

        temp._data = old_data;
        return *this;
    }

    // 6. Добавление элемента в конец
    void push_back(const T& value) {
        T value_copy = value;

        if (_size == _capacity) {
            size_t new_capacity =
                (_capacity == 0) ? 1 : _capacity * 2;

            if (new_capacity < _capacity) {
                throw std::length_error("Vector capacity overflow");
            }

            _resize_capacity(new_capacity);
        }

        _data[_size] = value_copy;
        ++_size;
    }

    // 7. Удаление последнего элемента
    void pop_back() {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }

        --_size;
    }

    // 8. Доступ по индексу без проверки границ
    T& operator[](size_t index) {
        return _data[index];
    }

    const T& operator[](size_t index) const {
        return _data[index];
    }

    // 9. Доступ по индексу с проверкой границ
    T& at(size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Vector index out of range");
        }

        return _data[index];
    }

    const T& at(size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("Vector index out of range");
        }

        return _data[index];
    }

    // 10. Первый элемент
    T& front() {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }

        return _data[0];
    }

    const T& front() const {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }

        return _data[0];
    }

    // 11. Последний элемент
    T& back() {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }

        return _data[_size - 1];
    }

    const T& back() const {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }

        return _data[_size - 1];
    }

    // 12. Количество элементов
    size_t size() const {
        return _size;
    }

    // 13. Выделенная ёмкость
    size_t capacity() const {
        return _capacity;
    }

    // 14. Проверка на пустоту
    bool empty() const {
        return _size == 0;
    }

    // 15. Резервирование памяти
    void reserve(size_t new_capacity) {
        if (new_capacity > _capacity) {
            _resize_capacity(new_capacity);
        }
    }

    // 16. Очистка контейнера
    void clear() {
        _size = 0;
    }

    // 17. Итератор на начало
    T* begin() {
        return _data;
    }

    const T* begin() const {
        return _data;
    }

    // 18. Итератор за последним элементом
    T* end() {
        return _data == nullptr ? nullptr : _data + _size;
    }

    const T* end() const {
        return _data == nullptr ? nullptr : _data + _size;
    }
};

#endif // VECTOR_H
