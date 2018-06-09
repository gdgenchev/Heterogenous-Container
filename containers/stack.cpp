#include<iostream>
#include<stdlib.h> //In order to use function exit() we need to add this library.
#include<cassert>
#include "../iterator/elem.h"

using namespace std;

template<typename T>
class Stack
{ 
private:
    elem<T>* el;

public:
    Stack();
    ~Stack();
    void push(const T&);
    void pop();
    T top() const;
    elem<T>* getTop () const {
        return el;
    }
    int size() const;
    bool isEmpty() const;
    void print(std::ostream& os = std::cout) const;
};

template<typename T>
Stack<T>::Stack()
{ el = nullptr;
}

template<typename T>
Stack<T>::~Stack()
{ while (!isEmpty())
        pop();
}

template<typename T>
void Stack<T>::push(const T &newelem) {
    elem<T>* nextelem = new elem<T>;
    assert(nextelem != nullptr);
    nextelem->inf = newelem;
    nextelem->next = el;
    el = nextelem;
}

template<typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        cerr << "There are no elements in the stack !" << endl;
        exit(1);
    }

    elem<T>* prev = el->next;
    delete el;
    el = prev;
}

template<typename T>
T Stack<T>::top() const
{ if (isEmpty())
    { cerr << "There are no elements in the stack !" << endl;
        exit(1);
    }

    return el->inf;
}

template<typename T>
int Stack<T>::size() const{
    int br = 0;
    elem<T>* topEl = el;
    while (topEl != nullptr) {
        br++;
        topEl = topEl->next;
    }
    return br;
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return el == nullptr;
}

template<typename T>
void Stack<T>::print(std::ostream& os) const {
    elem<T>* topEl = el;
    os << "Stack:";
    while (topEl != nullptr) {
        os << ' ' << topEl->inf;
        topEl = topEl->next;
    }
    os << std::endl;
}

