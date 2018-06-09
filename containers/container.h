//
// Created by georg on 12/30/2017.
//

#ifndef HETEROGENEOUS_CONTAINER_CONTAINER_H
#define HETEROGENEOUS_CONTAINER_CONTAINER_H

#include "../condition.h"
#include "queue.cpp"
#include "dllist.cpp"
#include "stack.cpp"
#include "../iterator/elem.h"
#include "../iterator/iterator.h"

template <typename T>
class Container {
public:
    virtual bool member(const T& x) = 0;
    virtual void push(const T& x) = 0;
    virtual void pop() = 0;
    virtual Iterator<T> getFirst() = 0;
    virtual Iterator<T> getLast() = 0;
    virtual bool getIteratorForX(const T& x, Iterator<T>& it) = 0;
    virtual int size() const = 0;
    virtual void sort() = 0;
    virtual bool isConditionValid (Condition<T> condition) = 0;
    virtual void removeElementsIf(Condition<T> condition) = 0;
    virtual void print(std::ostream& os = std::cout) const = 0;
};

#endif //HETEROGENEOUS_CONTAINER_CONTAINER_H
