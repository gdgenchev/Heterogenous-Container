#include<iostream>
#include<stdlib.h>
#include<cassert>
#include <vector>
#include <algorithm>
#include "../iterator/elem.h"

using namespace std;


template<typename T>
class Queue {
private:
    elem<T>* Front;
    elem<T>* End;

    void Copy(const Queue<T>&);
    void Erase();

public:
    Queue();
    Queue(const Queue<T>&);
    ~Queue();
    Queue& operator=(const Queue<T>&);
    void push(const T&);
    void pop();
    T front() const;
    elem<T>* getFront() const {
        return Front;
    }
    elem<T>* getEnd () const {
        return End;
    }
    bool isEmpty() const;
    int size() const;
    void print(std::ostream& os = std::cout) const;
};

template<typename T>
void Queue<T>::Copy(const Queue<T> &other) {
    elem<T>* otherFront = other.Front;

    while (otherFront) {
        push(otherFront->inf);
        otherFront = otherFront->next;
    }
}

template<typename T>
void Queue<T>::Erase() {
    while (!isEmpty())
        pop();
}

template<typename T>
Queue<T>::Queue() {
    Front = nullptr;
    End = nullptr;
}

template<typename T>
Queue<T>::Queue(const Queue<T> &other) {
    Front = nullptr;
    End = nullptr;
    Copy(other);
}

template<typename T>
Queue<T>::~Queue() {
    Erase();
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T> &other) {
    if (this != &other) {
        Erase();
        Copy(other);
    }

    return *this;
}

template<typename T>
void Queue<T>::push(const T &element) {
    elem<T>* save = End;
    End = new elem<T>;
    End->inf = element;
    End->next = nullptr;

    if (Front == nullptr)
        Front = End;

    else save->next = End;
}

template<typename T>
void Queue<T>::pop() {
    if (Front == nullptr) {
        cerr << "Error ! The queue is empty !" << endl;
        exit(1);
    }

    elem<T>* save = Front;
    Front = Front->next;
    delete save;
}

template<typename T>
T Queue<T>::front() const {
    if (isEmpty()) {
        cerr << "Error ! The queue is empty and there is no top element !" << endl;
        exit(1);
    }

    return Front->inf;
}

template<typename T>
bool Queue<T>::isEmpty() const {
    return Front == nullptr;
}

template<typename T>
int Queue<T>::size() const {
    elem<T>* it = Front;
    int br = 0;
    while (it != nullptr) {
        br++;
        it = it->next;
    }
    return br;
}

template<typename T>
void Queue<T>::print(std::ostream& os) const {
    elem<T>* it = Front;
    os << "Queue:";
    while (it != nullptr) {
        os << ' ' << it->inf;
        it = it->next;
    }
    os << std::endl;
}
