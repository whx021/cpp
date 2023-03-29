// myArray(test)

#include <iostream>
using namespace std;

template<class T>
class myArray {
public:
    myArray(int size = 0) : m_size(size) {}

    myArray(int size, const T& elem) : m_size(size) {
        this->m_arr = new T[size];
        for (int i = 0; i < size; ++i) {   
            this->m_arr[i] = elem;
        }
    }

    myArray(const myArray& arr) {
        this->m_size = arr.m_size;
        this->m_capacity = arr.m_capacity;
        this->m_arr = new T[arr.m_size];
        for (int i = 0; i < arr.m_size; ++i) {
            this->m_arr[i] = arr->m_arr;
        }
    }

    myArray& operator = (const myArray& arr) {
        this->m_size = 0;
        this->m_capacity = 0;
        if (this->m_arr != nullptr) {
            delete[] this->m_arr;
            this->m_arr = nullptr;
        }

        this->m_size = arr.m_size;
        this->m_capacity = arr.m_capacity;
        this->m_arr = new T[arr.m_size];
        for (int i = 0; i < arr.m_size; ++i) {
            this->m_arr[i] = arr.m_arr[i];
        }
    }

    void assign(int size, const T& elem) {
        this->m_arr = new T[size];
        for (int i = 0; i < size; ++i) {   
            this->m_arr[i] = elem;
        }
    }

    bool empty(void) const {
        if (this->m_size == 0) { 
            return true;
        }
        else {         
            return false;
        }
    }

    int size(void) const {
        return this->m_size;
    }

    const T& operator [] (int index) const {
        return this->m_arr[index];
    }

    void resize(int new_size, int elem = 0) {
        if (this->m_size >= new_size) {
            myArray temp = *this;

            if (this->m_arr != nullptr) {
                delete[] this->m_arr;
                this->m_arr = nullptr;
            }

            this->m_size = new_size;
            this->m_arr = new T[new_size];
            for (int i = 0; i < new_size; ++i) {
                this->m_arr[i] = temp.m_arr[i];
            }

            temp.~myArray();
        }
        else {
            myArray temp = *this;

            if (this->m_arr != nullptr) {
                delete[] this->m_arr;
                this->m_arr = nullptr;
            }
            
            this->m_size = new_size;
            this->m_arr = new T[new_size];
            for (int i = 0; i < temp->m_size; ++i) {
                this->m_arr[i] = temp.m_arr[i];
            }
            for (int i = temp->m_size; i < this->m_size; ++i) {
                this->m_arr[i] = elem;
            }

            temp.~myArray();

            /*
            TODO
            T* temp_arr = this->m_arr;
            int temp_size = this->m_size;
            */
        }
    }

    ~myArray() {
        this->m_size = 0;
        this->m_capacity = 0;
        if (this->m_arr != nullptr) {
            delete[] this->m_arr;
            this->m_arr = nullptr;
        }
    }
private:
    T*  m_arr[];
    int m_size;
};