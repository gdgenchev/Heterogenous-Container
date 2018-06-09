//
// Created by georg on 1/4/2018.
//

#ifndef HETEROGENEOUS_CONTAINER_ITERATOR_H
#define HETEROGENEOUS_CONTAINER_ITERATOR_H

#include "elem.h"

template <typename T>
class Iterator {
private:
    elem<T>* ptr;
public:
    explicit Iterator(elem<T>* ptr) : ptr(ptr) {};

    Iterator() {
        ptr = nullptr;
    }

    void operator ++() {
        ptr = ptr->next;
    }

    T operator *() const {
        if (ptr != nullptr) {
             return ptr->inf;
         }
    }

    bool operator == (const Iterator<T>& other) {
        return ptr == other.ptr;
    }

    bool operator != (const Iterator<T>& other) const {
        return ptr != other.ptr;
    }

    Iterator<T> next () {
        if (ptr->next != nullptr)
            return Iterator<T>(ptr->next);
    }

    bool valid() {
        return ptr != nullptr;
    }
};
#endif //HETEROGENEOUS_CONTAINER_ITERATOR_H
