#include <iostream>

class MyVector {
    private:
        int* ptr;
        size_t _size;
        size_t _capacity;
        

    public:

         MyVector() {
            _size = 0;
            _capacity = 0;
            ptr = nullptr;
        }
         MyVector () {
            delete[] ptr;
            _size = 0;
            _capacity = 0;
            ptr = nullptr;
        }

        MyVector(size_t size) {
            ptr = new int[size];
            _size = size;
            _capacity = size;
            for(int i = 0; i < size; ++i) {
                ptr[i] = 0;
            }
        }

        MyVector(size_t size, int value) {
            ptr = new int[size];
            _size = size;
            _capacity = size;
            for (int i = 0; i < size; ++i) {
                ptr[i] = value;
            }
        }

        size_t size() {
            return _size;
        }

        size_t capacity() {
            return _capacity;
        }

        void push_back (int value) {
            if(_size >= _capacity) {
                size_t newcap = _capacity * 2;
                int* newPtr = new int [newcap];
                for (int i = 0; i < _size; ++i) {
                    newPtr[i] = ptr[i];
                }
                delete[] ptr;
                ptr = newPtr;
                _capacity = newcap;
            }
            ptr[_size] = value;
            ++_size;
        }

        void pop_back() {
            if(_size == 0) {
                std::cout << "vector is empty" << std::endl;
            }
            --_size;

        }

        void resize(size_t newSize) {
            if (newSize > _capacity) {
                int newcap = _capacity * 2;
                int* newPtr = new int [newSize];
                for (int i = 0; i < _size; ++i) {
                    newPtr[i] = ptr[i];
                }
                delete[] ptr;
                ptr = newPtr;
                _capacity = newcap;
            }

            if (newSize > _size) {
                for(int i = _size; i < newSize; ++i) {
                    ptr[i] = 0;
                }
            }
            _size = newSize;
        }

    void clear() {
        _size = 0;
    }

}
