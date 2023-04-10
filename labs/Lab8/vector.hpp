#include <stdlib.h>
#include <stdexcept>

template <class T>
class vector {
private:
    T* v;
    int s;
    int c;

public:
    // CONSTRUCTOR
    vector() {
        s = 0;
        c = 0;
        v = nullptr;
    }

    // copy constructor
    vector(vector<T> &other) {
        s = other.s;
        c = other.c;
        v = new T[c];
        for (int i = 0; i < s; i++) {
            v[i] = other[i];
        }
    }

    // DECONSTRUCTOR
    ~vector(){
        delete[] v;
    }

    // HELPER METHODS
    int size() {
        return s;
    }

    void push_back(T ele) {
        // allocates a temporary pointer
        T* temp;
        // increase size
        s++;
        // increase capacity
        if (s > c) {
            c++;
        }
        temp = new T[c];
        // copies all the old objects
        for (int i = 0; i < s - 1; i++) {
            temp[i] = v[i];
        }
        // deletes the old pointer array
        delete[] v;
        v = temp;
        // adds the new object
        v[s - 1] = ele;
    }

    void resize(int new_s, T val=T()) {
        // https://www.cplusplus.com/reference/vector/vector/resize/
        
    }

    // OPERATOR OVERLOADS
    // assignment operator
    void operator=(vector<T> &other) {
        s = other.s;
        c = other.c;
        // check if v is nullptr
        if (v != nullptr) {
            delete[] v;
        }
        v = new T[c];
        for (int i = 0; i < s; i++) {
            v[i] = other[i];
        }
    }

    // indexing operator
    T& operator[](int index) {
        if (-1 < index && index < s) {
            return v[index];
        } else {
            throw std::out_of_range("index out of range for vector");
        }
    }

    T& at(int index) {
        return operator[](index);
    }
};
